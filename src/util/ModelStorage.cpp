//
// Created by eal on 19/12-2025.
//

#include "ModelStorage.hpp"

#include "spdlog/fmt/bundled/chrono.h"

ModelStorage::ModelStorage(const std::shared_ptr<spdlog::logger>& logger) : logger_(logger)
{
}

void ModelStorage::addClub(const std::shared_ptr<Club>& club)
{
  if (club->getUuid().empty())
  {
    auto uuid = generateUuid();
    club->setUuid(uuid);
  }
  clubs_[club->getUuid()] = club;
  logger_->info("Added Club with UUID: {}", club->getUuid());
}

void ModelStorage::addPlayer(const std::shared_ptr<Player>& player)
{
  if (player->getUuid().empty())
  {
    auto uuid = generateUuid();
    player->setUuid(uuid);
  }
  players_[player->getUuid()] = player;
  logger_->info("Added Player with UUID: {}", player->getUuid());
}

void ModelStorage::addLeague(const std::shared_ptr<League>& league)
{
  if (league->getUuid().empty())
  {
    auto uuid = generateUuid();
    league->setUuid(uuid);
  }
  leagues_[league->getUuid()] = league;
  logger_->info("Added League with UUID: {}", league->getUuid());
}

std::shared_ptr<Club> ModelStorage::getClub(const std::string& uuid)
{
  return clubs_.at(uuid);
}

std::shared_ptr<Player> ModelStorage::getPlayer(const std::string& uuid)
{
  return players_.at(uuid);
}

std::shared_ptr<League> ModelStorage::getLeague(const std::string& uuid)
{
  return leagues_.at(uuid);
}

std::string ModelStorage::generateUuid()
{
  // TODO Implement a proper UUID generator here, this is good enough for now.
  static int counter = 0;
  return "uuid-" + std::to_string(counter++);
}
