//
// Created by eal on 19/12-2025.
//

#include "Player.hpp"

Player::Player(const std::string& name, int age, const std::shared_ptr<TimeKeeper>& timeKeeper, const std::shared_ptr<spdlog::logger>& logger) : name_(name), age_(age), logger_(logger), timeKeeper_(timeKeeper)
{
  updateAge();
}

void Player::setUuid(const std::string& uuid)
{
  uuid_ = uuid;
}

std::string Player::getUuid() const
{
  return uuid_;
}

void Player::setClubId(const std::string& clubId)
{
  clubId_ = clubId;
}

std::string Player::getClubId() const
{
  return clubId_;
}

std::string Player::getName() const
{
  return name_;
}

int Player::getAge() const
{
  return age_;
}

void Player::updateAge()
{
  timeKeeper_->scheduleEvent(timeKeeper_->getCurrentSeconds() + 31536000, [this]() {
    age_ += 1;
    logger_->info("Player {} has turned {} years old.", name_, age_);
    updateAge();
  });
}
