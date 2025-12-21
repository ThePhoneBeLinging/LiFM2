//
// Created by eal on 19/12-2025.
//

#include "MockDataCreator.hpp"

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
  return league->getUuid();
}
