//
// Created by EAL on 27/04/2025.
//

#include "LiFM/LiFM.hpp"
#include "models/Club.hpp"
#include "spdlog/spdlog.h"
#include "Time/TimeKeeper.hpp"

void LiFM::launch()
{
  auto logger = spdlog::default_logger();
  auto timeKeeper = std::make_shared<TimeKeeper>(logger);
  auto club1 = std::make_shared<Club>("Alpha FC", timeKeeper, logger);
  auto club2 = std::make_shared<Club>("Beta United", timeKeeper, logger);


  for (int i = 0; i < 100; i++)
  {
    timeKeeper->advance();
  }
}
