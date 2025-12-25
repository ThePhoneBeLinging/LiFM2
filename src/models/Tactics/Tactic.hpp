//
// Created by eal on 22/12-2025.
//

#ifndef TACTIC_HPP
#define TACTIC_HPP
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "Positions/Position.hpp"

struct Tactic
{
public:
  bool setPlayerPosition(const std::string& playerId, const std::shared_ptr<Position>& position)
  {
    if (activePlayers_.size() >= 11 && not activePlayers_.contains(playerId))
    {
      return false;
    }
    if (not activePlayers_.contains(playerId))
    {
      activePlayers_.insert(playerId);
    }

    positions_[playerId] = position;

    return true;
  }

  bool removePlayer(const std::string& playerId)
  {
    if (not activePlayers_.contains(playerId))
    {
      return false;
    }

    activePlayers_.erase(playerId);
    positions_.erase(playerId);
    return true;
  }

  [[nodiscard]] std::vector<std::string> getActivePlayers() const
  {
    return {activePlayers_.begin(), activePlayers_.end()};
  }

private:
  std::unordered_set<std::string> activePlayers_;
  std::unordered_map<std::string, std::shared_ptr<Position>> positions_;
};

#endif //TACTIC_HPP
