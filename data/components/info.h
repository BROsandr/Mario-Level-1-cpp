#pragma once

#include <map>
#include <string_view>
#include <SFML/Graphics/Sprite.hpp>

#include "tools.h"

struct OverheadInfo {
 public:
  OverheadInfo(std::map<std::string_view, int> game_info, State* state);

  sf::Sprite sprite_sheet;
};
