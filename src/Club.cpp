//
// Created by eal on 16/12-2025.
//

#include "Club.hpp"

#include <iostream>

Club::Club(const std::string& name, const std::shared_ptr<TimeKeeper>& timeKeeper) : name_(name), timeKeeper_(timeKeeper)
{
  std::cout << "Club " << name_ << " created." << std::endl;
  timeKeeper_->scheduleEvent(10, [this]() { this->handleTraining(); });
  timeKeeper_->scheduleEvent(20, [this]() { this->handleTransfers(); });
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
