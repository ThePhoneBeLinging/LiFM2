//
// Created by eal on 21/12-2025.
//

#ifndef MATCHSIM_HPP
#define MATCHSIM_HPP
#include "ModelStorage.hpp"
#include "models/Match.hpp"


class MatchSim {
public:
  static void simulateMatch(ModelStorage* modelStorage, const std::shared_ptr<TimeKeeper>& timeKeeper, const std::shared_ptr<spdlog::logger>& logger, Match match);
private:
};



#endif //MATCHSIM_HPP
