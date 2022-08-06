#pragma once 

#include <SFML/Graphics/RenderWindow.hpp>

struct Screen {
 public:
  static sf::RenderWindow& instance(); 

  Screen(const Screen&) = delete;
  void operator=(const Screen&) = delete;

 private:
  Screen() {};
}; 
