//
// Created by Elias Aggergaard Larsen on 25/12-2025.
//

#ifndef LIFM_POSITION_HPP
#define LIFM_POSITION_HPP
#include <string>
#include <vector>

class Position
{
public:
  virtual ~Position() = default;
  [[nodiscard]] virtual std::string getName() const = 0;
  [[nodiscard]] virtual std::string getAbbreviation() const = 0;
  [[nodiscard]] virtual std::vector<std::string> getPossibleRoles() const = 0;
};


#endif //LIFM_POSITION_HPP
