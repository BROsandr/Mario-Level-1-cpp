#pragma once

#include "main_menu.h"

#include "constants.h"

Menu::Menu() {
  persist = {{kCointTotal, 0},
             {kScore, 0},
             {kLives, 3},
             {kTopScore, 0},
             {kCurrentTime, 0.0},
             {kLevelState, -1},
             {kCameraStartX, 0},
             {kMarioDead, false}};
  Startup(0.0, persist);
}

void Menu::Startup(double current_time, std::map<const char*, int> _persist) {
  next = kLoadScreen;
  persist = _persist;
  game_info = _persist;
  overhead_info = std::make_unique<OverheadInfo>(game_info, kMainMenu);

  LoadSpriteSheet(
}
