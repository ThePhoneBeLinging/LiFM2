//
// Created by EAL on 27/04/2025.
//

#include "LiFM/LiFM.hpp"
#include "models/Club.hpp"
#include "spdlog/spdlog.h"
#include "Time/TimeKeeper.hpp"
#include "util/MockDataCreator.hpp"
#include "util/ModelStorage.hpp"

void LiFM::launch()
{
  auto logger = spdlog::default_logger();
  auto timeKeeper = std::make_shared<TimeKeeper>(logger);
  auto modelStorage = std::make_unique<ModelStorage>(logger);
  auto leagueId = MockDataCreator::createSuperliga(timeKeeper, modelStorage.get(), logger);

  auto league = modelStorage->getLeague(leagueId);

  for (int i = 0; i < 7500; i++)
  {
    timeKeeper->advance();
  }
  for (const auto& club : league->getClubIds())
  {
    auto clubModel = modelStorage->getClub(club);
    logger->info("Club: {} has {} points", clubModel->getName(), league->getPoints(club));
  }
}
