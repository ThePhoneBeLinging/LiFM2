//
// Created by eal on 19/12-2025.
//

#ifndef MOCKDATACREATOR_HPP
#define MOCKDATACREATOR_HPP
#include <string>

#include "ModelStorage.hpp"


class MockDataCreator {
public:
  static std::string createSuperliga(const std::shared_ptr<TimeKeeper>& timeKeeper, ModelStorage* modelStorage, const std::shared_ptr<spdlog::logger>& logger);
private:
  static std::string createRandomPlayer(ModelStorage* modelStorage, const std::shared_ptr<spdlog::logger>& logger);
};



#endif //MOCKDATACREATOR_HPP
