#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include <string_view>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <string>

std::map<std::string_view, sf::Keyboard::Key>& keybinding();

class State {
 public:
  explicit State();

  std::map<std::string_view, int> Cleanup();
  void Startup(double current_time, std::map<std::string_view, int> persistant);
  virtual void Update(sf::Keyboard::Key keys, double current_time) = 0;

  double start_time{0.0};
  double current_time{0.0};
  bool done{false};
  bool quit{false};
  std::string next{""};
  std::string previous{""};
  std::map<std::string_view, int> persist;
};

class Control {
 public:
  explicit Control(const char caption[]);

  void SetupStates(std::map<std::string_view, State*>& state_dict, const char start_state[]);
  void main();
  void EventLoop();
  void Update();
  void FlipState(); 

  bool done{false};
  sf::Clock clock;
  const char* caption{""};
  const int fps{60};
  bool show_fps{false};
  double current_time{0.0};
  sf::Keyboard::Key keys;
  std::map<std::string_view, State*> state_dict;
  std::string state_name{""};
  State* state{nullptr};
};

