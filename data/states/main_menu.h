#pragma once

#include <list>

#include "tools.h"
#include "components/mario.h"

class Menu : public State {
 public:
  explicit Menu();

  void Update(sf::Keyboard::Key keys, double current_time) override;
  void Startup(double current_time, std::map<std::string, int> persist) override;
  sf::Sprite GetImage(int x, int y, int width, int height, sf::Image& sprite_sheet);
  void SetupBackground();
  void SetupMario();
  void SetupCursor();

  std::list<sf::Texture> textures;
  sf::Sprite cursor;
  Mario mario;
  std::map<std::string, sf::Sprite> image_dict;
  sf::Sprite background;
};
