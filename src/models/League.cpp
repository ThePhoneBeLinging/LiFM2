//
// Created by eal on 19/12-2025.
//

#include "League.hpp"

League::League(const std::string& name, const std::shared_ptr<TimeKeeper>& timeKeeper, const std::shared_ptr<spdlog::logger>& logger) : name_(name), logger_(logger), timeKeeper_(timeKeeper)
{
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
  return std::vector<std::string>(clubIds_.begin(), clubIds_.end());
}
