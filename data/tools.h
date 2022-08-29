#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <map>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <filesystem>
#include <SFML/Graphics/Texture.hpp>


std::map<const char*, sf::Keyboard::Key>& keybinding();

class State {
 public:
  explicit State();
  ~State();

  std::map<const char*, int> Cleanup();
  virtual void Startup(double current_time, std::map<const char*, int> persist);
  virtual void Update(sf::Keyboard::Key keys, double current_time) = 0;

  double start_time{0.0};
  double current_time{0.0};
  bool done{false};
  bool quit{false};
  const char* next{""};
  const char* previous{""};
  std::map<const char*, int> persist;
  std::map<const char*, int> game_info;
  class OverheadInfo;
  std::unique_ptr<OverheadInfo> overhead_info;
};

class Control {
 public:
  explicit Control(const char caption[]);

  void SetupStates(std::map<const char*, State*>& state_dict, const char start_state[]);
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
  sf::Keyboard::Key keys{sf::Keyboard::Key::Unknown};
  std::map<const char*, State*> state_dict;
  const char* state_name{""};
  State* state{nullptr};
};

std::map<const char*, sf::Image>& LoadAllGfx(std::filesystem::path directory,
                                             std::vector<const char*> accept = {"png", 
                                                                                "jpg",
                                                                                "bmp"},
                                             sf::Color colorkey = {255, 0, 255});

void LoadSpriteSheet(sf::Color colorkey, const char* texture_name, sf::Texture& sprite_sheet);

struct Image {
 public:

};
