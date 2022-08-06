#include "setup.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include "constants.h"

sf::RenderWindow& Window::instance() {
  static sf::RenderWindow instance(sf::VideoMode(kScreenSize[0], kScreenSize[1]),
                                   "");
  
  return instance;
}
