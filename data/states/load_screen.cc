#include "load_screen.h"

#include "setup.h"
#include "constants.h"
#include "components/info.h"

void LoadScreen::Update(sf::Keyboard::Key keys, double current_time) {
  if ((current_time - start_time) < 2400) {
    Window::instance().clear(sf::Color::Black);
    overhead_info->Update(game_info);
  }
}

void LoadScreen::Startup(double current_time, std::map<const char*, int> _persist) {
  State::Startup(current_time, _persist);
  game_info = persist;
  next = SetNextState();

  const char* info_state{SetOverheadInfoState()};

  overhead_info = std::make_unique<OverheadInfo>(game_info, info_state);
}

const char* LoadScreen::SetNextState() {
  return kLevel1;
}

const char* LoadScreen::SetOverheadInfoState() {
  return kLoadScreen;
}
