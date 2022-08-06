#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include <string_view>
#include <SFML/Window/Keyboard.hpp>

std::map<std::string_view, sf::Keyboard::Key>& keybinding();

class State {
 public:
  explicit State();
};

class Control {
 public:
  explicit Control();

  void SetupStates(std::map<std::string_view, State>& state_dict, const char start_state[]);

  bool done{false};
  sf::Clock clock;
  const char* caption{""};
  const int fps{60};
  bool show_fps{false};
  double current_time{0.0};
  std::map<std::string_view, State> state_dict;
  const char* state_name{""};
  State state;
};

