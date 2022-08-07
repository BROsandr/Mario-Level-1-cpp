#pragma once

#include "tools.h"

class LoadScreen : public State {
 public:
  explicit LoadScreen() {};

  void Update(sf::Keyboard::Key keys, double current_time) override;
  void Startup(double current_time, std::map<std::string_view, int> persist) override;
  std::string_view SetNextState();
  std::string_view SetOverheadInfoState();

  std::map<std::string_view, int> game_info;
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
