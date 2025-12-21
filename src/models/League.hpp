//
// Created by eal on 19/12-2025.
//

#ifndef LEAGUE_HPP
#define LEAGUE_HPP
#include <memory>
#include <unordered_set>
#include "spdlog/spdlog.h"
#include "Time/TimeKeeper.hpp"

class ModelStorage;
class League {
public:
  League(const std::string& name, const std::shared_ptr<TimeKeeper>& timeKeeper, ModelStorage* modelStorage, const std::shared_ptr<spdlog::logger>& logger);
  void setUuid(const std::string& uuid);
  std::string getUuid() const;
  void addClub(const std::string& clubId);
  void removeClub(const std::string& clubId);
  std::vector<std::string> getClubIds();

private:
  void createMatches(ModelStorage* modelStorage);

  std::string uuid_;
  std::unordered_set<std::string> clubIds_;

  std::string name_;
  std::shared_ptr<spdlog::logger> logger_;
  std::shared_ptr<TimeKeeper> timeKeeper_;
};



#endif //LEAGUE_HPP
