//
// Created by eal on 16/12-2025.
//

#include "Club.hpp"
#include <iostream>

#include "Tactics/Positions/LeftBack.hpp"
#include "util/ModelStorage.hpp"

Club::Club(const std::string& name, const std::shared_ptr<TimeKeeper>& timeKeeper, ModelStorage* modelStorage,
           const std::shared_ptr<spdlog::logger>& logger) : name_(name), timeKeeper_(timeKeeper), logger_(logger),
                                                            tactic_(std::make_unique<Tactic>())
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
  auto position = std::make_shared<LeftBack>();
  tactic_->setPlayerPosition(playerId, position);
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

void Club::handleTransferOffer(const std::string& transferOfferId, ModelStorage* modelStorage)
{
  auto offer = modelStorage->getTransferOffer(transferOfferId);
  logger_->info("Handling transfer Offer: {}", offer->getPlayerId());

  timeKeeper_->scheduleEvent(timeKeeper_->getCurrentSeconds(), [transferOfferId, modelStorage, offer]()
  {
    auto toClubId = offer->getToClubId();
    auto toClub = modelStorage->getClub(toClubId);
    offer->setState(TransferState::ACCEPTED);
    toClub->handleTransferOfferReply(transferOfferId, true, modelStorage);
  });
}

void Club::handleTransferOfferReply(const std::string& transferOfferId, const bool accepted, ModelStorage* modelStorage)
{
  auto offer = modelStorage->getTransferOffer(transferOfferId);
  auto details = offer->getDetails();
  logger_->info("Looking at reply: {}", offer->getPlayerId());
  if (accepted)
  {
    timeKeeper_->scheduleEvent(offer->getDetails()->timeOfTransfer_, [offer, details, modelStorage]()
    {
      auto player = modelStorage->getPlayer(offer->getPlayerId());
      auto club = modelStorage->getClub(player->getClubId());
      club->removePlayer(player->getUuid());
      player->setClubId(offer->getToClubId());
      auto newClub = modelStorage->getClub(offer->getToClubId());
      newClub->addPlayer(player->getUuid());
      offer->setState(TransferState::COMPLETED);
    });
  }
}

void Club::handleTraining(ModelStorage* modelStorage)
{
  timeKeeper_->scheduleEvent(timeKeeper_->getCurrentSeconds() + 10,
                             [this, modelStorage]() { this->handleTraining(modelStorage); });
}
