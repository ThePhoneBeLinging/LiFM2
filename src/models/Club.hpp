//
// Created by eal on 16/12-2025.
//

#ifndef CLUB_HPP
#define CLUB_HPP
#include <string>

#include "../Time/TimeKeeper.hpp"


class Club {
public:
  explicit Club(const std::string& name, const std::shared_ptr<TimeKeeper>& timeKeeper, const std::shared_ptr<spdlog::logger>& logger);
  void setUuid(const std::string& uuid);
  std::string getUuid() const;

  void handleTraining();
  void handleTransfers();

private:
  std::string uuid_;
  std::string name_;
  std::shared_ptr<TimeKeeper> timeKeeper_;
  std::shared_ptr<spdlog::logger> logger_;
};



#endif //CLUB_HPP
