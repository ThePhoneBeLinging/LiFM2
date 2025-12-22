//
// Created by eal on 22/12-2025.
//

#ifndef TACTIC_HPP
#define TACTIC_HPP
#include <string>
#include <unordered_map>
#include <unordered_set>

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
  std::unordered_set<std::string> activePlayers_;
  std::unordered_map<std::string, Position> positions_;
};

#endif //TACTIC_HPP
