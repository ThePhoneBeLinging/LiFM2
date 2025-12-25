//
// Created by Elias Aggergaard Larsen on 25/12-2025.
//

#ifndef LIFM_LEFTBACK_HPP
#define LIFM_LEFTBACK_HPP
#include "Position.hpp"


class LeftBack : public Position
{
public:
  LeftBack() = default;
  [[nodiscard]] std::string getName() const override;
  [[nodiscard]] std::string getAbbreviation() const override;
  [[nodiscard]] std::vector<std::string> getPossibleRoles() const override;

private:
};


#endif //LIFM_LEFTBACK_HPP
