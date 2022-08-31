#include "info.h"

#include <list>

#include "constants.h"
#include "setup.h"

OverheadInfo::OverheadInfo(std::map<std::string, int>& _game_info, const char* _state) {
  sf::Image image{gfx().at("text_images")};
  image.createMaskFromColor({92, 148, 252});
  sprite_sheet.loadFromImage(image);

  coin_total = _game_info.at(kCointTotal);
  time = 401;
  current_time = 0;
  total_lives = _game_info.at(kLives);
  top_score = _game_info.at(kTopScore);
  state = _state;
  game_info = _game_info;

  CreateImageDict();
  CreateScoreGroup();
  CreateMainMenuLabels();
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

  for (auto& character : character_string) {
    image_dict[character] = image_list.front();
    image_list.pop_front();
  }
      
}

sf::Sprite OverheadInfo::GetImage(int x, int y, int width, int height) {
  sf::Sprite sprite{sprite_sheet, {x, y, width, height}};
  sprite.scale({2.9, 2.9});
  return sprite;
}

void OverheadInfo::Draw() {
  if (!strcmp(state, kMainMenu)) {
    DrawMainMenuInfo();
  } else if (state == kLoadScreen) {
    DrawLoadingScreenInfo();
  }
}

void OverheadInfo::DrawLoadingScreenInfo() {
  for (auto& info : score_images)
    Window::instance().draw(info);
}

void OverheadInfo::CreateScoreGroup() {
  CreateLabel(score_images, "000000", 75, 55);
}

void OverheadInfo::CreateLabel(std::list<sf::Sprite>& label_list,
                               const std::string& string,
                               int x,
                               int y) {
  for (auto& letter : string) 
    label_list.push_back(image_dict.at(letter));

  SetLabelRects(label_list, x, y);
}

void OverheadInfo::SetLabelRects(std::list<sf::Sprite>& label_list, int x, int y) {
  int i{0};
  for (auto& letter : label_list) {
    letter.setPosition(x + ((letter.getGlobalBounds().width + 3) * i++), y);
    //if (letter.getTexture() == image_dict.at('-').getTexture()) 
    //  letter.setPosition(letter.getPosition().x + 7, letter.getPosition().y + 2);
  }
}

void OverheadInfo::Update(std::map<std::string, int>& level_info) {
}

void OverheadInfo::DrawMainMenuInfo() {
  for (auto& info : score_images) 
    Window::instance().draw(info);

  for (auto& label : main_menu_labels) 
    for (auto& letter : label) 
      Window::instance().draw(letter);
}

void OverheadInfo::CreateMainMenuLabels() {
  std::list<sf::Sprite> player_one_game;
  std::list<sf::Sprite> player_two_game;
  std::list<sf::Sprite> top;
  std::list<sf::Sprite> top_score;

  CreateLabel(player_one_game, "1 PLAYER GAME", 272, 360);
  CreateLabel(player_two_game, "2 PLAYER GAME", 272, 405);
  CreateLabel(top, "TOP - ", 290, 465);
  CreateLabel(top_score, "000000", 400, 465);
  
  main_menu_labels = {player_one_game, player_two_game, top, top_score};
}
