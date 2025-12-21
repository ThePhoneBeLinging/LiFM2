//
// Created by EAL on 27/04/2025.
//

#include "LiFM/LiFM.hpp"
#include "models/Club.hpp"
#include "spdlog/spdlog.h"
#include "Time/TimeKeeper.hpp"
#include "util/ModelStorage.hpp"

void LiFM::launch()
{
  auto logger = spdlog::default_logger();
  auto timeKeeper = std::make_shared<TimeKeeper>(logger);
  auto modelStorage = std::make_unique<ModelStorage>(logger);
  auto club1 = std::make_shared<Club>("Alpha FC", timeKeeper, modelStorage.get(), logger);
  auto club2 = std::make_shared<Club>("Beta United", timeKeeper, modelStorage.get(), logger);
  modelStorage->addClub(club1);
  modelStorage->addClub(club2);


  for (int i = 0; i < 100; i++)
  {
    timeKeeper->advance();
  }
}
