//
// Created by eal on 19/12-2025.
//

#include "League.hpp"

League::League(const std::string& name, const std::shared_ptr<spdlog::logger>& logger) : name_(name), logger_(logger)
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
