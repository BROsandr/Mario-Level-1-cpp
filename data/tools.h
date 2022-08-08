#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <map>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <string>
#include <filesystem>
#include <SFML/Graphics/Texture.hpp>

std::map<std::string_view, sf::Keyboard::Key>& keybinding();

class State {
 public:
  explicit State();

  std::map<const char*, int> Cleanup();
  virtual void Startup(double current_time, std::map<const char*, int> persist);
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
  void ToggleShowFps(sf::Keyboard::Key key);

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

std::map<std::string_view, sf::Image>& LoadAllGfx(std::filesystem::path directory,
                                                    std::vector<std::string_view> accept = {"png", 
                                                                                            "jpg",
                                                                                            "bmp"},
                                                    sf::Color colorkey = {255, 0, 255});
