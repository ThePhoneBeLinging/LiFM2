#include "LiFM/LiFM.hpp"
#include "Utility/ConfigController.h"

int main()
{
  ConfigController::loadConfig("../config.json");
  auto game = LiFM();
  game.launch();
  return 0;
}
