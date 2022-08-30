#pragma once

#include <memory>

#include "tools.h"
#include "components/info.h"

class LoadScreen : public State {
 public:
  explicit LoadScreen() {};

  void Update(sf::Keyboard::Key keys, double current_time) override;
  void Startup(double current_time, std::map<std::string, int> persist) override;
  const char* SetNextState();
  const char* SetOverheadInfoState();
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
