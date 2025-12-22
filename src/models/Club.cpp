//
// Created by eal on 16/12-2025.
//

#include "Club.hpp"
#include <iostream>

#include "util/ModelStorage.hpp"

Club::Club(const std::string& name, const std::shared_ptr<TimeKeeper>& timeKeeper, ModelStorage* modelStorage, const std::shared_ptr<spdlog::logger>& logger) : name_(name), timeKeeper_(timeKeeper), logger_(logger), tactic_(std::make_unique<Tactic>())
{
  logger_->info("Creating club: {}", name_);
  //timeKeeper_->scheduleEvent(0, [this, modelStorage]() { this->handleTraining(modelStorage); });
  //timeKeeper_->scheduleEvent(0, [this, modelStorage]() { this->handleTransfers(modelStorage); });
}

void Club::setUuid(const std::string& uuid)
{
  uuid_ = uuid;
}

void Club::addPlayer(const std::string& playerId)
{
  playerIds_.insert(playerId);
  if (tactic_->activePlayers_.size() < 11)
  {
    tactic_->activePlayers_.insert(playerId);
  }
}

void Club::removePlayer(const std::string& playerId)
{
  playerIds_.erase(playerId);
}

void Club::setLeague(const std::string& leagueId)
{
  leagueId_ = leagueId;
}

std::string Club::getUuid() const
{
  return uuid_;
}

std::string Club::getLeagueId()
{
  return leagueId_;
}

std::vector<std::string> Club::getPlayerIds()
{
  return std::vector<std::string>(playerIds_.begin(), playerIds_.end());
}

std::string Club::getName() const
{
  return name_;
}

Tactic* Club::getTactic()
{
  return tactic_.get();
}

void Club::handleTraining(ModelStorage* modelStorage)
{
  timeKeeper_->scheduleEvent(timeKeeper_->getCurrentSeconds() + 10, [this, modelStorage]() { this->handleTraining(modelStorage); });
}

void Club::handleTransfers(ModelStorage* modelStorage)
{
  timeKeeper_->scheduleEvent(timeKeeper_->getCurrentSeconds() + 20, [this, modelStorage]() { this->handleTransfers(modelStorage); });
}
