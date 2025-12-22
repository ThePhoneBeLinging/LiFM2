//
// Created by eal on 16/12-2025.
//

#ifndef CLUB_HPP
#define CLUB_HPP
#include <string>
#include <unordered_set>

#include "Tactic.hpp"
#include "Time/TimeKeeper.hpp"

class ModelStorage;
class Club {
public:
  explicit Club(const std::string& name, const std::shared_ptr<TimeKeeper>& timeKeeper, ModelStorage* modelStorage, const std::shared_ptr<spdlog::logger>& logger);
  void setUuid(const std::string& uuid);
  void addPlayer(const std::string& playerId);
  void removePlayer(const std::string& playerId);
  void setLeague(const std::string& leagueId);

  std::string getUuid() const;
  std::string getLeagueId();
  std::vector<std::string> getPlayerIds();
  std::string getName() const;
  Tactic* getTactic();

  void handleTraining(ModelStorage* modelStorage);
  void handleTransfers(ModelStorage* modelStorage);

private:
  std::string uuid_;
  std::string leagueId_;
  std::unordered_set<std::string> playerIds_;
  std::string name_;
  std::shared_ptr<TimeKeeper> timeKeeper_;
  std::shared_ptr<spdlog::logger> logger_;
  std::unique_ptr<Tactic> tactic_;
};



#endif //CLUB_HPP
