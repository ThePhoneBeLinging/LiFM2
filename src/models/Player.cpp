//
// Created by eal on 19/12-2025.
//

#include "Player.hpp"

Player::Player(const std::string& name, int age, const std::shared_ptr<spdlog::logger>& logger) : name_(name), age_(age), logger_(logger)
{
}

void Player::setUuid(const std::string& uuid)
{
  uuid_ = uuid;
}

std::string Player::getUuid() const
{
  return uuid_;
}

std::string Player::getName() const
{
  return name_;
}

int Player::getAge() const
{
  return age_;
}
