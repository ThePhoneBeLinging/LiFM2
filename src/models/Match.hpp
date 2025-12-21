//
// Created by eal on 21/12-2025.
//

#ifndef MATCH_HPP
#define MATCH_HPP
#include <memory>

struct Match
{
  std::string homeClubId;
  std::string awayClubId;
  std::string leagueId;
  int homeGoals;
  int awayGoals;
  int matchTimeSeconds;
};

#endif //MATCH_HPP
