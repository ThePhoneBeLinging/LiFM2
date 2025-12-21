//
// Created by eal on 19/12-2025.
//

#include "League.hpp"

#include "util/MatchSim.hpp"

League::League(const std::string& name, const std::shared_ptr<TimeKeeper>& timeKeeper, ModelStorage* modelStorage, const std::shared_ptr<spdlog::logger>& logger) : name_(name), logger_(logger), timeKeeper_(timeKeeper)
{
  timeKeeper_->scheduleEvent(0, [this, modelStorage]() { createMatches(modelStorage); });
}

void League::setUuid(const std::string& uuid)
{
  uuid_ = uuid;
}

std::string League::getUuid() const
{
  return uuid_;
}

void League::addClub(const std::string& clubId)
{
  clubIds_.insert(clubId);
}

void League::removeClub(const std::string& clubId)
{
  clubIds_.erase(clubId);
}

std::vector<std::string> League::getClubIds()
{
  return {clubIds_.begin(), clubIds_.end()};
}

void League::createMatches(ModelStorage* modelStorage)
{
  logger_->info("Creating matches for league: {}", name_);
  for (const auto& clubId : clubIds_)
  {
    for (const auto& opponentId : clubIds_)
    {
      if (clubId != opponentId)
      {
        auto match = Match();
        match.homeClubId = clubId;
        match.awayClubId = opponentId;
        match.leagueId = uuid_;
        timeKeeper_->scheduleEvent(timeKeeper_->getCurrentSeconds() + 1, [modelStorage, match, this]() {
          MatchSim::simulateMatch(modelStorage, timeKeeper_, logger_, match);
        });
      }
    }
  }
}
