#include "setup.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include "constants.h"
#include "tools.h"

sf::RenderWindow& Window::instance() {
  static sf::RenderWindow instance(sf::VideoMode(kScreenSize[0], kScreenSize[1]),
                                   "");
  
  return instance;
}

std::map<std::string_view, sf::Texture>& gfx() {
  return LoadAllGfx(std::filesystem::path("resources") / "graphics");
}
