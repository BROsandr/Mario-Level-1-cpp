#pragma once

#include <map>
#include <list>
#include <SFML/Graphics/Sprite.hpp>

#include "tools.h"

struct OverheadInfo {
 public:
  OverheadInfo(std::map<std::string, int>& game_info, const char* state);

  void CreateImageDict();
  sf::Sprite GetImage(int x, int y, int width, int height);
  void Draw();
  void DrawLoadingScreenInfo();
  void DrawMainMenuInfo();
  void CreateScoreGroup();
  void CreateMainMenuLabels();
  void CreateLabel(std::list<sf::Sprite>& label_list, 
                   const std::string& string, 
                   int x, 
                   int y);
  void SetLabelRects(std::list<sf::Sprite>& label_list, int x, int y);
  void Update(std::map<std::string, int>& level_info);

  sf::Texture sprite_sheet;
  int coin_total{-1};
  double time{-1};
  double current_time{-1};
  int total_lives{-1};
  int top_score{-1};
  const char* state{""};
  std::map<std::string, int> game_info;
  std::map<char, sf::Sprite> image_dict;
  std::list<sf::Sprite> score_images;
  std::list<std::list<sf::Sprite>> main_menu_labels;
};
