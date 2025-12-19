//
// Created by eal on 16/12-2025.
//

#include "Club.hpp"
#include <iostream>

Club::Club(const std::string& name, const std::shared_ptr<TimeKeeper>& timeKeeper, const std::shared_ptr<spdlog::logger>& logger) : name_(name), timeKeeper_(timeKeeper), logger_(logger)
{
  logger_->info("Creating club: {}", name_);
  timeKeeper_->scheduleEvent(0, [this]() { this->handleTraining(); });
  timeKeeper_->scheduleEvent(0, [this]() { this->handleTransfers(); });
}

void Club::setUuid(const std::string& uuid)
{
  uuid_ = uuid;
}

std::string Club::getUuid() const
{
  return uuid_;
}

void Club::handleTraining()
{
  timeKeeper_->scheduleEvent(timeKeeper_->getCurrentSeconds() + 10, [this]() { this->handleTraining(); });
  std::cout << "Club " << name_ << " is handling training at time " << timeKeeper_->getCurrentSeconds() << std::endl;
}

void Club::handleTransfers()
{
  timeKeeper_->scheduleEvent(timeKeeper_->getCurrentSeconds() + 20, [this]() { this->handleTransfers(); });
  std::cout << "Club " << name_ << " is handling transfers at time " << timeKeeper_->getCurrentSeconds() << std::endl;
}
