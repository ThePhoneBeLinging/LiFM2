//
// Created by eal on 22/12-2025.
//

#ifndef TACTIC_HPP
#define TACTIC_HPP
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

enum class Position
{
  GOALKEEPER,
  LEFT_BACK,
  RIGHT_BACK,
  CENTER_BACK,
  DEFENSIVE_MIDFIELDER,
  CENTRAL_MIDFIELDER,
  ATTACKING_MIDFIELDER,
  LEFT_WINGER,
  RIGHT_WINGER,
  STRIKER,
};

struct Tactic
{
public:
  bool setPlayerPosition(const std::string& playerId, Position position)
  {
    if (activePlayers_.size() >= 11)
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

  std::vector<std::string> getActivePlayers() const
  {
    return std::vector<std::string>(activePlayers_.begin(), activePlayers_.end());
  }

private:
  std::unordered_set<std::string> activePlayers_;
  std::unordered_map<std::string, Position> positions_;
};

#endif //TACTIC_HPP
