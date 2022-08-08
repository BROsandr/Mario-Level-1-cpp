#include <SFML/Graphics/RenderWindow.hpp>
#include <map>

#include "tools.h"
#include "constants.h"
#include "states/main_menu.h"
#include "states/level1.h"
#include "states/load_screen.h"

int main() {

  Control run_it{kOriginalCaption};

  Menu menu;
  LoadScreen load_screen;
  GameOver game_over;
  Level1 level1;

  std::map<const char*, State*> state_dict{
      {kMainMenu, &menu},
      {kLoadScreen, &load_screen},
      {kGameOver, &game_over},
      {kLevel1, &level1}
  };

  run_it.SetupStates(state_dict, kMainMenu);
  run_it.main();
}
