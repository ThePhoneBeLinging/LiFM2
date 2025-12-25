//
// Created by Elias Aggergaard Larsen on 25/12-2025.
//

#include "LeftBack.hpp"

std::string LeftBack::getName() const
{
  return "Left Back";
}

std::string LeftBack::getAbbreviation() const
{
  return "LB";
}

std::vector<std::string> LeftBack::getPossibleRoles() const
{
  return {"Full Back", "Wing Back"};
}
