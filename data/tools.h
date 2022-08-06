#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include <string_view>
#include <SFML/Window/Keyboard.hpp>

std::map<std::string_view, sf::Keyboard::Key>& keybinding();

class State {
 public:
  explicit State(sf::RenderWindow& screen);

};

class Control {
 public:
  explicit Control(const char* caption);

  void SetupStates(std::map<std::string_view, State>& state_dict, State& start_state);
  void set_state_dict(std::map<std::string_view, State> state_dict);
  void set_state_name(char* state_name);
  void set_state(State state);

 private:
  sf::RenderWindow& screen_;
  bool done_{false};
  sf::Clock clock_;
  const char* caption_{""};
  const int fps_{60};
  bool show_fps_{false};
  double current_time_{0.0};
  std::map<std::string_view, State> state_dict_;
  char* state_name_;
  State state_;
};

