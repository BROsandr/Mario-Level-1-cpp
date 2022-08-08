#include "info.h"

#include <list>

#include "constants.h"
#include "setup.h"

OverheadInfo::OverheadInfo(std::map<const char*, int> _game_info, std::string& _state) {
  sf::Image image{gfx()["text_images"]};
  image.createMaskFromColor({92, 148, 252});
  sprite_sheet.loadFromImage(image);

  coin_total = _game_info[kCointTotal];
  time = 401;
  current_time = 0;
  total_lives = _game_info[kLives];
  top_score = _game_info[kTopScore];
  state = _state;
  game_info = _game_info;

  CreateImageDict();
}

void OverheadInfo::CreateImageDict() {
  std::list<sf::Sprite> image_list;

  image_list.push_back(GetImage(3, 230, 7, 7));
  image_list.push_back(GetImage(12, 230, 7, 7));
  image_list.push_back(GetImage(19, 230, 7, 7));
  image_list.push_back(GetImage(27, 230, 7, 7));
  image_list.push_back(GetImage(35, 230, 7, 7));
  image_list.push_back(GetImage(43, 230, 7, 7));
  image_list.push_back(GetImage(51, 230, 7, 7));
  image_list.push_back(GetImage(59, 230, 7, 7));
  image_list.push_back(GetImage(67, 230, 7, 7));
  image_list.push_back(GetImage(75, 230, 7, 7));


  image_list.push_back(GetImage(83, 230, 7, 7));
  image_list.push_back(GetImage(91, 230, 7, 7));
  image_list.push_back(GetImage(99, 230, 7, 7));
  image_list.push_back(GetImage(107, 230, 7, 7));
  image_list.push_back(GetImage(115, 230, 7, 7));
  image_list.push_back(GetImage(123, 230, 7, 7));
  image_list.push_back(GetImage(3, 238, 7, 7));
  image_list.push_back(GetImage(11, 238, 7, 7));
  image_list.push_back(GetImage(20, 238, 7, 7));
  image_list.push_back(GetImage(27, 238, 7, 7));
  image_list.push_back(GetImage(35, 238, 7, 7));
  image_list.push_back(GetImage(44, 238, 7, 7));
  image_list.push_back(GetImage(51, 238, 7, 7));
  image_list.push_back(GetImage(59, 238, 7, 7));
  image_list.push_back(GetImage(67, 238, 7, 7));
  image_list.push_back(GetImage(75, 238, 7, 7));
  image_list.push_back(GetImage(83, 238, 7, 7));
  image_list.push_back(GetImage(91, 238, 7, 7));
  image_list.push_back(GetImage(99, 238, 7, 7));
  image_list.push_back(GetImage(108, 238, 7, 7));
  image_list.push_back(GetImage(115, 238, 7, 7));
  image_list.push_back(GetImage(123, 238, 7, 7));
  image_list.push_back(GetImage(3, 246, 7, 7));
  image_list.push_back(GetImage(11, 246, 7, 7));
  image_list.push_back(GetImage(20, 246, 7, 7));
  image_list.push_back(GetImage(27, 246, 7, 7));
  image_list.push_back(GetImage(48, 248, 7, 7));


  image_list.push_back(GetImage(68, 249, 6, 2));
  image_list.push_back(GetImage(75, 247, 6, 6));

  std::string_view character_string{"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ -*"};

  for (auto character : character_string) {
    image_dict[character] = image_list.front();
    image_list.pop_front();
  }
      
}

sf::Sprite OverheadInfo::GetImage(int x, int y, int width, int height) {
  sf::Sprite sprite{sprite_sheet, {x, y, width, height}};
  sprite.scale({2.9, 2.9});
  return sprite;
}
