//
// Created by eal on 19/12-2025.
//

#include "MockDataCreator.hpp"

#include "RandomNumberGenerator.hpp"

std::string MockDataCreator::createSuperliga(const std::shared_ptr<TimeKeeper>& timeKeeper, ModelStorage* modelStorage,
                                             const std::shared_ptr<spdlog::logger>& logger)
{
  auto league = std::make_shared<League>("Danish Superliga", timeKeeper, modelStorage, logger);
  modelStorage->addLeague(league);
  auto brondby = std::make_shared<Club>("Brøndby IF", timeKeeper, modelStorage, logger);
  auto copenhagen = std::make_shared<Club>("FC Copenhagen", timeKeeper, modelStorage, logger);
  auto midtjylland = std::make_shared<Club>("FC Midtjylland", timeKeeper, modelStorage, logger);

  modelStorage->addClub(brondby);
  modelStorage->addClub(copenhagen);
  modelStorage->addClub(midtjylland);
  league->addClub(brondby->getUuid());
  league->addClub(copenhagen->getUuid());
  league->addClub(midtjylland->getUuid());
  brondby->setLeague(league->getUuid());
  copenhagen->setLeague(league->getUuid());
  midtjylland->setLeague(league->getUuid());

  for (int i = 0; i < 25; i++)
  {
    brondby->addPlayer(createRandomPlayer(brondby->getUuid(), modelStorage, timeKeeper, logger));
    copenhagen->addPlayer(createRandomPlayer(copenhagen->getUuid(), modelStorage, timeKeeper, logger));
    midtjylland->addPlayer(createRandomPlayer(midtjylland->getUuid(), modelStorage, timeKeeper, logger));
  }

  return league->getUuid();
}

std::string MockDataCreator::createRandomPlayer(const std::string& clubId, ModelStorage* modelStorage,
                                                const std::shared_ptr<TimeKeeper>& timeKeeper,
                                                const std::shared_ptr<spdlog::logger>& logger)
{
  static int counter = 1;
  auto playerName = "Player_" + std::to_string(counter++);
  auto player = std::make_shared<Player>(playerName, RandomNumberGenerator::randomInt(16, 45), timeKeeper, logger);
  player->setClubId(clubId);
  modelStorage->addPlayer(player);
  return player->getUuid();
}
