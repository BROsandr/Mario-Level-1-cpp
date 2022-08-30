#include "mario.h"

#include "setup.h"
#include "constants.h"

Mario::Mario() { 
  sf::Image image{gfx().at("mario_bros")};
  image.createMaskFromColor(sf::Color::Black);
  sprite_sheet.loadFromImage(image);

  LoadImagesFromSheet();

  this->image = right_frames.at(frame_index);
}

sf::Sprite Mario::GetImage(int x, int y, int width, int height) {
  sf::Sprite sprite{sprite_sheet, {x, y, width, height}};
  sprite.scale({kSizeMultiplier, kSizeMultiplier});
  return sprite;
}

void Mario::LoadImagesFromSheet() {
  std::vector<sf::Sprite> right_small_normal_frames;
  std::vector<sf::Sprite> left_small_normal_frames;
  std::vector<sf::Sprite> right_small_green_frames;
  std::vector<sf::Sprite> left_small_green_frames;
  std::vector<sf::Sprite> right_small_red_frames;
  std::vector<sf::Sprite> left_small_red_frames;
  std::vector<sf::Sprite> right_small_black_frames;
  std::vector<sf::Sprite> left_small_black_frames;

  std::vector<sf::Sprite> right_big_normal_frames;
  std::vector<sf::Sprite> left_big_normal_frames;
  std::vector<sf::Sprite> right_big_green_frames;
  std::vector<sf::Sprite> left_big_green_frames;
  std::vector<sf::Sprite> right_big_red_frames;
  std::vector<sf::Sprite> left_big_red_frames;
  std::vector<sf::Sprite> right_big_black_frames;
  std::vector<sf::Sprite> left_big_black_frames;

  std::vector<sf::Sprite> right_fire_frames;
  std::vector<sf::Sprite> left_fire_frames;

  right_small_normal_frames.push_back(GetImage(178, 32, 12, 16));
  right_small_normal_frames.push_back(GetImage(80, 32, 15, 16));
  right_small_normal_frames.push_back(GetImage(96, 32, 16, 16));
  right_small_normal_frames.push_back(GetImage(112, 32, 16, 16));
  right_small_normal_frames.push_back(GetImage(144, 32, 16, 16));
  right_small_normal_frames.push_back(GetImage(130, 32, 12, 16));
  right_small_normal_frames.push_back(GetImage(160, 32, 12, 16));
  right_small_normal_frames.push_back(GetImage(320, 8, 16, 24));
  right_small_normal_frames.push_back(GetImage(241, 33, 16, 16));
  right_small_normal_frames.push_back(GetImage(194, 32, 12, 16));
  right_small_normal_frames.push_back(GetImage(210, 33, 12, 16));

  right_small_normal_frames.push_back(GetImage(176, 0, 16, 32));
  right_small_normal_frames.push_back(GetImage(81, 0, 16, 32));
  right_small_normal_frames.push_back(GetImage(97, 0, 15, 32));
  right_small_normal_frames.push_back(GetImage(113, 0, 15, 32));
  right_small_normal_frames.push_back(GetImage(144, 0, 16, 32));
  right_small_normal_frames.push_back(GetImage(128, 0, 16, 32));
  right_small_normal_frames.push_back(GetImage(336, 0, 16, 32));
  right_small_normal_frames.push_back(GetImage(160, 10, 16, 22));
  right_small_normal_frames.push_back(GetImage(272, 2, 16, 29));
  right_small_normal_frames.push_back(GetImage(193, 2, 16, 30));
  right_small_normal_frames.push_back(GetImage(209, 2, 16, 29));

  for (auto frame : right_small_normal_frames) {
    sf::Sprite new_image{frame};
    new_image.setOrigin({ new_image.getLocalBounds().width, 0 });
    new_image.setScale({ -1, 1 });
    left_small_normal_frames.push_back(new_image);
  }

  for (auto frame : left_small_normal_frames) {
    sf::Sprite new_image{frame};
    new_image.setOrigin({ new_image.getLocalBounds().width, 0 });
    new_image.setScale({ -1, 1 });
    right_small_normal_frames.push_back(new_image);
  }

  right_frames = right_small_normal_frames;
  left_frames = left_small_normal_frames;
}

void Mario::Update() { 
  Animation(); 
}

void Mario::Animation() {
  if (facing_right) {
    image = right_frames[frame_index];
  } else {
    image = left_frames[frame_index]; 
  }
}
