#include "tools.h"

#include <SFML/Window/Event.hpp>

#include "setup.h"

std::map<std::string_view, sf::Keyboard::Key>& keybinding() {
  static std::map<std::string_view, sf::Keyboard::Key> keybinding;
  return keybinding;
}

Control::Control(const char caption[]) {
  Window::instance().setTitle(caption);
}

State::State() {
}

void Control::SetupStates(std::map<std::string_view, State*>& _state_dict, const char _start_state[]) {
  state_dict = _state_dict;
  state_name = _start_state;
  state = state_dict[state_name];
}

void Control::main() {
  while (!done && Window::instance().isOpen()) {
    EventLoop();
  }
}

void Control::EventLoop() {
  sf::Event event;
  while (Window::instance().pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      Window::instance().close();
    } else if (event.type == sf::Event::KeyPressed) {
      keys = event.key.code;
      ToggleShowFps(keys);
    } else if (event.type == sf::Event::KeyReleased) {
      keys = event.key.code;
    }
  }
}

void Control::Update() {
  current_time = clock.getElapsedTime().asSeconds();
  
  if (state->done)
    FlipState();
    
  state->Update(keys, current_time);
}

void Control::FlipState() {
  std::string previous{state_name};
  state_name = state->next;
  std::map<std::string_view, int> persist = state->Cleanup();
  state = state_dict[state_name];
  state->Startup(current_time, persist);
  state->previous = previous;
}

std::map<std::string_view, int> State::Cleanup() {
  done = false;
  return persist;
}

void State::Startup(double current_time, std::map<std::string_view, int> persistant) {
  persist = persistant;
  start_time = current_time;
}
