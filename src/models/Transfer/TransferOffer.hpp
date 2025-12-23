//
// Created by Elias Aggergaard Larsen on 22/12-2025.
//

#ifndef LIFM_TRANSFEROFFER_HPP
#define LIFM_TRANSFEROFFER_HPP
#include <memory>
#include <string>

#include "TransferDetails.hpp"
#include "TransferState.hpp"

class ModelStorage;

class TransferOffer
{
public:
  TransferOffer(const std::string& playerId, const std::string& toClubId);
  void setUuid(const std::string& uuid);
  void setState(const TransferState& state);
  void send(ModelStorage* modelStorage);

  [[nodiscard]] std::string getUuid() const;
  [[nodiscard]] std::string getPlayerId() const;
  [[nodiscard]] std::string getToClubId() const;
  TransferDetails* getDetails();
  TransferState getState();

private:
  std::string uuid_;
  std::string playerId_;
  std::string toClubId_;
  TransferState state_;
  std::unique_ptr<TransferDetails> details_;
};


#endif //LIFM_TRANSFEROFFER_HPP
