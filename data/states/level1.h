#pragma once

#include "tools.h"

class Level1 : public State {
 public:
  explicit Level1() {};

  void Update(sf::Keyboard::Key keys, double current_time) override {};
};
