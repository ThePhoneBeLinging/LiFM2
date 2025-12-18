//
// Created by eal on 16/12-2025.
//

#ifndef CLUB_HPP
#define CLUB_HPP
#include <string>

#include "Time/TimeKeeper.hpp"


class Club {
public:
  explicit Club(const std::string& name, const std::shared_ptr<TimeKeeper>& timeKeeper, const std::shared_ptr<spdlog::logger>& logger);

  void handleTraining();
  void handleTransfers();

private:
  std::string name_;
  std::shared_ptr<TimeKeeper> timeKeeper_;
  std::shared_ptr<spdlog::logger> logger_;
};



#endif //CLUB_HPP
