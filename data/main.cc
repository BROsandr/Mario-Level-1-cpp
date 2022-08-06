#include <SFML/Graphics/RenderWindow.hpp>
#include <map>

#include "tools.h"
#include "constants.h"
#include "states/main_menu.h"
#include "states/level1.h"
#include "states/load_screen.h"

int main() {

  Control run_it;
  std::map<std::string_view, State> state_dict{
      {kMainMenu, Menu{}},
      {kLoadScreen, LoadScreen{}},
      {kGameOver, GameOver{}},
      {kLevel1, Level1{}}
  };

  run_it.SetupStates(state_dict, kMainMenu);
}
