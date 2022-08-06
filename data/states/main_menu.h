#pragma once

#include "tools.h"

class Menu : public State {
 public:
  explicit Menu() {};

  void Update(sf::Keyboard::Key keys, double current_time) override {};
};
