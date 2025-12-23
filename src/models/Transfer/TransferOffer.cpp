//
// Created by Elias Aggergaard Larsen on 22/12-2025.
//

#include "TransferOffer.hpp"

#include "util/ModelStorage.hpp"

TransferOffer::TransferOffer(const std::string& playerId, const std::string& toClubId) : playerId_(playerId),
  toClubId_(toClubId), state_(TransferState::NOT_SENT),
  details_(std::make_unique<TransferDetails>())
{
}

void TransferOffer::setUuid(const std::string& uuid)
{
  uuid_ = uuid;
}

void TransferOffer::setState(const TransferState& state)
{
  state_ = state;
}

void TransferOffer::send(ModelStorage* modelStorage)
{
  state_ = TransferState::PENDING;
  auto toClub = modelStorage->getClub(toClubId_);
  toClub->handleTransferOffer(uuid_, modelStorage);
}

std::string TransferOffer::getUuid() const
{
  return uuid_;
}

std::string TransferOffer::getPlayerId() const
{
  return playerId_;
}

std::string TransferOffer::getToClubId() const
{
  return toClubId_;
}

TransferDetails* TransferOffer::getDetails()
{
  return details_.get();
}

TransferState TransferOffer::getState()
{
  return state_;
}
