//
// Created by Elias Aggergaard Larsen on 23/12-2025.
//

#ifndef LIFM_TRANSFERSTATE_HPP
#define LIFM_TRANSFERSTATE_HPP

enum class TransferState
{
  NOT_SENT,
  PENDING,
  PENDING_CONTRACT,
  ACCEPTED,
  REJECTED,
  COMPLETED
};

#endif //LIFM_TRANSFERSTATE_HPP
