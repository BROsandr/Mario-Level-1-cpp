#include "info.h"

#include "constants.h"
#include "setup.h"

OverheadInfo::OverheadInfo(std::map<std::string_view, int> _game_info, char* _state) {
  sprite_sheet.setTexture(gfx()["text_images"]);
  coin_total = _game_info[kCointTotal];
  time = 401;
  current_time = 0;
  total_lives = _game_info[kLives];
  top_score = _game_info[kTopScore];
  state = _state;
  game_info = _game_info;
}
