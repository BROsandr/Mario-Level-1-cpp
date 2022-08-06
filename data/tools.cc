#include "tools.h"

std::map<std::string_view, sf::Keyboard::Key>& keybinding() {
  static std::map<std::string_view, sf::Keyboard::Key> keybinding;
  return keybinding;
}

Control::Control(const char* caption) {
}

State::State(sf::RenderWindow& screen) : screen_{screen} {
}

void Control::SetupStates(std::map<std::string_view, State>& state_dict, State& start_state) {
  set_state_dict(state_dict);
}


void Control::set_state_dict(std::map<std::string_view, State> state_dict) {
  state_dict_ = state_dict;
}

void Control::set_state_name(char* state_name) {
  state_name_ = state_name;
}

void Control::set_state(State state) {
  state_ = state;
}
