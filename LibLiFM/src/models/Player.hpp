//
// Created by eal on 19/12-2025.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <memory>

#include "spdlog/spdlog.h"
#include "Time/TimeKeeper.hpp"


class Player {
public:
  Player(const std::string& name, int age, const std::shared_ptr<TimeKeeper>& timeKeeper, const std::shared_ptr<spdlog::logger>& logger);
  void setUuid(const std::string& uuid);
  [[nodiscard]] std::string getUuid() const;
  void setClubId(const std::string& clubId);
  [[nodiscard]] std::string getClubId() const;

  [[nodiscard]] std::string getName() const;
  [[nodiscard]] int getAge() const;

private:
  void updateAge();

  std::string uuid_;
  std::string clubId_;

  std::string name_;
  int age_;
  std::shared_ptr<spdlog::logger> logger_;
  std::shared_ptr<TimeKeeper> timeKeeper_;
};



#endif //PLAYER_HPP
