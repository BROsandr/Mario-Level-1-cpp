#include "info.h"

#include "setup.h"

OverheadInfo::OverheadInfo(std::map<std::string_view, int> game_info, State* state) {
  sprite_sheet.setTexture(gfx()["text_images"]);
}
