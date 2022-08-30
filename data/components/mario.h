#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>

struct Mario {
 public:
  explicit Mario();

  sf::Sprite GetImage(int x, int y, int width, int height); 
  void LoadImagesFromSheet();
  void Update();
  void Animation();

  sf::Texture sprite_sheet;
  std::vector<sf::Sprite> right_frames;
  std::vector<sf::Sprite> left_frames;
  int frame_index{0};
  sf::Sprite image;
  bool facing_right{true};
};
