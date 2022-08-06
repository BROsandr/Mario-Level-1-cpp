#include <tools.h>

std::map<std::string_view, sf::Keyboard::Key>& keybinding() {
  static std::map<std::string_view, sf::Keyboard::Key> keybinding;
  return keybinding;
}
