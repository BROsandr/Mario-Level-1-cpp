#pragma once

#include <map>
#include <string_view>

#include <SFML/Window/Keyboard.hpp>

std::map<std::string_view, sf::Keyboard::Key>& keybinding();

class Control {
};
