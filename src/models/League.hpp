//
// Created by eal on 19/12-2025.
//

#ifndef LEAGUE_HPP
#define LEAGUE_HPP
#include <memory>
#include "spdlog/spdlog.h"

class League {
public:
  League(const std::string& name, const std::shared_ptr<spdlog::logger>& logger);
  void setUuid(const std::string& uuid);
  std::string getUuid() const;

private:
  std::string uuid_;

  std::string name_;
  std::shared_ptr<spdlog::logger> logger_;
};



#endif //LEAGUE_HPP
