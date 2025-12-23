//
// Created by Elias Aggergaard Larsen on 22/12-2025.
//

#include "TransferOffer.hpp"

TransferOffer::TransferOffer(const std::string& playerId, const std::string& toClubId) : playerId_(playerId),
  toClubId_(toClubId),
  details_(std::make_unique<TransferDetails>())
{
}

void TransferOffer::setUuid(const std::string& uuid)
{
  uuid_ = uuid;
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
