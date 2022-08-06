#include "tools.h"

std::map<std::string_view, sf::Keyboard::Key>& keybinding() {
  static std::map<std::string_view, sf::Keyboard::Key> keybinding;
  return keybinding;
}

Control::Control() {
}

State::State() {
}

void Control::SetupStates(std::map<std::string_view, State>& _state_dict, const char _start_state[]) {
  state_dict = _state_dict;
  state_name = _start_state;
  state = state_dict[state_name];
}
