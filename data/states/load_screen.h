#pragma once

#include "tools.h"

class LoadScreen : public State {
 public:
  explicit LoadScreen() {};

  void Update(sf::Keyboard::Key keys, double current_time) override;
};

class GameOver : public State {
 public:
  explicit GameOver() {};

  void Update(sf::Keyboard::Key keys, double current_time) override {};
};

class TimeOut : public State {
 public:
  explicit TimeOut() {};

  void Update(sf::Keyboard::Key keys, double current_time) override {};
};
