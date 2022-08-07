#include "load_screen.h"

#include "setup.h"
#include "constants.h"

void LoadScreen::Update(sf::Keyboard::Key keys, double current_time) {
  if ((current_time - start_time) < 2400) {
    Window::instance().clear(sf::Color::Black);
  }
}

void LoadScreen::Startup(double current_time, std::map<std::string_view, int> _persist) {
  State::Startup(current_time, _persist);
  game_info = persist;
  next = SetNextState();

  std::string_view info_state{SetOverheadInfoState()};
}

std::string_view LoadScreen::SetNextState() {
  return kLevel1;
}

std::string_view LoadScreen::SetOverheadInfoState() {
  return kLoadScreen;
}
