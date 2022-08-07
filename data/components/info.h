#pragma once

#include <map>
#include <string_view>
#include <SFML/Graphics/Sprite.hpp>

#include "tools.h"

struct OverheadInfo {
 public:
  OverheadInfo(std::map<std::string_view, int> game_info, char* state);

  sf::Sprite sprite_sheet;
  int coin_total{-1};
  double time{-1};
  double current_time{-1};
  int total_lives{-1};
  int top_score{-1};
  std::string state{""};
  std::map<std::string_view, int> game_info;
};
