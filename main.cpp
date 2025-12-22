#include <thread>

#include "LiFM/LiFM.hpp"
#include "Utility/ConfigController.h"

int main()
{
  auto game = LiFM();
  game.launch();
  return 0;
}
