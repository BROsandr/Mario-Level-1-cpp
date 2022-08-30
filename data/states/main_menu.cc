#include "main_menu.h"

#include "components/info.h"

#include "constants.h"
#include "setup.h"

Menu::Menu() {
  persist = {{kCointTotal, 0},
             {kScore, 0},
             {kLives, 3},
             {kTopScore, 0},
             {kCurrentTime, 0.0},
             {kLevelState, -1},
             {kCameraStartX, 0},
             {kMarioDead, false}};
  Startup(0.0, persist);
}

void Menu::Startup(double current_time, std::map<std::string, int> _persist) {
  next = kLoadScreen;
  persist = _persist;
  game_info = _persist;
  overhead_info = std::make_unique<OverheadInfo>(game_info, kMainMenu);

  SetupBackground();
  SetupMario();
  SetupCursor();
}

sf::Sprite Menu::GetImage(int x, int y, int width, int height, sf::Image& _sprite_sheet) {
  sf::Image image;
  image.create(width, height);
  image.copy(_sprite_sheet, 0, 0, {x, y, width, height});
  sf::Sprite sprite;
  textures.push_back({});
  if (&_sprite_sheet == &gfx().at("title_screen")) {
    image.createMaskFromColor({255, 0, 220});
    textures.back().loadFromImage(image);
    sprite.setTexture(textures.back());
    sprite.scale(kSizeMultiplier, kSizeMultiplier);
  } else {
    image.createMaskFromColor(sf::Color::Black);
    textures.back().loadFromImage(image);
    sprite.setTexture(textures.back());
    sprite.scale(3, 3);
  }
  return sprite;
}

void Menu::SetupBackground() {
  textures.push_back({});
  textures.back().loadFromImage(gfx().at("level_1"));
  background.setTexture(textures.back());
  background.scale(kBackgroundMultiplier, kBackgroundMultiplier);
  
  image_dict["GAME_NAME_BOX"] = GetImage(1, 60, 176, 88, gfx().at("title_screen"));
  image_dict["GAME_NAME_BOX"].setPosition(170, 100);
}

void Menu::SetupMario() {
  mario.setPosition(110, kGroundHeight);
}

void Menu::SetupCursor() {
  cursor = GetImage(24, 160, 8, 8, gfx().at("item_objects"));
  cursor.setPosition(220, 358);
}

void Menu::Update(sf::Keyboard::Key keys, double _current_time) {
  current_time = _current_time;
  game_info.at(kCurrentTime) = current_time;
  overhead_info->Update(game_info);

  Window::instance().draw(background);
  Window::instance().draw(image_dict.at("GAME_NAME_BOX"));
  Window::instance().draw(mario);
  Window::instance().draw(cursor);
}
