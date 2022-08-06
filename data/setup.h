#pragma once 

#include <SFML/Graphics/RenderWindow.hpp>

struct Window {
 public:
  static sf::RenderWindow& instance(); 

  Window(const Window&) = delete;
  void operator=(const Window&) = delete;

 private:
  explicit Window() {};
}; 
