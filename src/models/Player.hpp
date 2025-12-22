//
// Created by eal on 19/12-2025.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <memory>

#include "spdlog/spdlog.h"


class Player {
public:
  Player(const std::string& name, int age, const std::shared_ptr<spdlog::logger>& logger);
  void setUuid(const std::string& uuid);
  [[nodiscard]] std::string getUuid() const;

private:
  std::string uuid_;

  std::string name_;
  int age_;
  std::shared_ptr<spdlog::logger> logger_;
};



#endif //PLAYER_HPP
