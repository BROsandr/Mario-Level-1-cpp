#pragma once

#include <map>
#include <SFML/Graphics/Sprite.hpp>

#include "tools.h"

struct OverheadInfo {
 public:
  OverheadInfo(std::map<const char*, int> game_info, std::string& state);

  void CreateImageDict();
  sf::Sprite GetImage(int x, int y, int width, int height);

  sf::Texture sprite_sheet;
  int coin_total{-1};
  double time{-1};
  double current_time{-1};
  int total_lives{-1};
  int top_score{-1};
  std::string state{""};
  std::map<const char*, int> game_info;
  std::map<char, sf::Sprite> image_dict;
};
