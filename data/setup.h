#pragma once 

#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include <filesystem>

struct Window {
 public:
  static sf::RenderWindow& instance(); 

  Window(const Window&) = delete;
  void operator=(const Window&) = delete;

 private:
  explicit Window() {};
}; 

std::map<std::string, sf::Image>& gfx();
