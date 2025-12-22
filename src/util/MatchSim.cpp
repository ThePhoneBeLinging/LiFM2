//
// Created by eal on 21/12-2025.
//

#include "MatchSim.hpp"

#include "RandomNumberGenerator.hpp"

void MatchSim::simulateMatch(ModelStorage* modelStorage, const std::shared_ptr<TimeKeeper>& timeKeeper,
                             const std::shared_ptr<spdlog::logger>& logger, Match match)
{
  match.matchTimeSeconds++;
  auto homeClub = modelStorage->getClub(match.homeClubId);
  auto awayClub = modelStorage->getClub(match.awayClubId);

  auto homeTactic = homeClub->getTactic();
  auto awayTactic = awayClub->getTactic();

  if (match.matchTimeSeconds >= 90 * 60)
  {
    logger->info("Match ended {} : {} between {} and {}", match.homeGoals, match.awayGoals, homeClub->getName(),
                 awayClub->getName());
    auto league = modelStorage->getLeague(homeClub->getLeagueId());
    if (match.homeGoals > match.awayGoals)
    {
      league->updateLeagueTable(homeClub->getUuid(), 3);
    }
    else if (match.homeGoals < match.awayGoals)
    {
      league->updateLeagueTable(awayClub->getUuid(), 3);
    }
    else
    {
      league->updateLeagueTable(homeClub->getUuid(), 1);
      league->updateLeagueTable(awayClub->getUuid(), 1);
    }
    return;
  }
  int randomInt = RandomNumberGenerator::randomInt(0, 3600); // Average of 3 goals per 90 minutes
  if (randomInt == 0)
  {
    auto homePlayers = homeTactic->getActivePlayers();
    auto homePlayerId = homePlayers[RandomNumberGenerator::randomInt(0, 10)];
    logger->info("Player {} scored for {}", modelStorage->getPlayer(homePlayerId)->getName(), homeClub->getName());
    match.homeGoals++;
  }
  else if (randomInt == 1)
  {
    auto awayPlayers = awayTactic->getActivePlayers();
    auto awayPlayerId = awayPlayers[RandomNumberGenerator::randomInt(0, 10)];
    logger->info("Player {} scored for {}", modelStorage->getPlayer(awayPlayerId)->getName(), awayClub->getName());
    match.awayGoals++;
  }


  timeKeeper->scheduleEvent(timeKeeper->getCurrentSeconds() + 1, [modelStorage, timeKeeper, logger, match]()
  {
    simulateMatch(modelStorage, timeKeeper, logger, match);
  });
}
