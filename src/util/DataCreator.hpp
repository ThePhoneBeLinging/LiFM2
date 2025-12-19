//
// Created by eal on 19/12-2025.
//

#ifndef DATACREATOR_HPP
#define DATACREATOR_HPP
#include "ModelStorage.hpp"
#include "spdlog/spdlog.h"

class DataCreator
{
public:
  virtual ~DataCreator() = default;
  virtual void fetchData(ModelStorage& modelStorage, const std::shared_ptr<spdlog::logger>& logger) = 0;
};

#endif //DATACREATOR_HPP
