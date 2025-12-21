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
  if (match.matchTimeSeconds >= 90 * 60)
  {
    logger->info("Match ended [{} : {}] between {} and {}", match.homeGoals, match.awayGoals ,homeClub->getName(), awayClub->getName());
    return;
  }
  int randomInt = RandomNumberGenerator::randomInt(0, 3600); // Average of 3 goals per 90 minutes
  if (randomInt == 0)
  {
    logger->info("Goal for home team!");
    match.homeGoals++;
  }
  else if (randomInt == 1)
  {
    logger->info("Goal for away team!");
    match.awayGoals++;
  }


  timeKeeper->scheduleEvent(timeKeeper->getCurrentSeconds() + 1, [modelStorage, timeKeeper, logger, match]() {simulateMatch(modelStorage, timeKeeper, logger, match);});
}
