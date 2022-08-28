#pragma once

#include "tools.h"

class Menu : public State {
 public:
  explicit Menu();

  void Update(sf::Keyboard::Key keys, double current_time) override {};
  void Startup(double current_time, std::map<const char*, int> persist) override;

  sf::Texture sprite_sheet;
};
