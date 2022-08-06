#include "setup.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include "constants.h"

sf::RenderWindow& Screen::instance() {
  static sf::RenderWindow instance(sf::VideoMode(kScreenSize[0], kScreenSize[1]), 
             kOriginalCaption);
  
  return instance;
}
