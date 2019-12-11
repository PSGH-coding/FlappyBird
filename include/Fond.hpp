#ifndef FOND_HPP
#define FOND_HPP
#include "Textures.hpp"

#define SCROLL_FOND 0.5
#define SCROLL_SPEED 2

class Fond{
private:
  sf::Sprite sprite;
  sf::Sprite sprite2;
  sf::Sprite sol;
  sf::Sprite sol2;
  float long_sprite;
  float long_sol;
public:
  Fond(Textures & textures);

  sf::Sprite get_sprite(void);
  sf::Sprite get_sprite2(void);
  sf::Sprite get_sol(void);
  sf::Sprite get_sol2(void);

  void move_fond(void);
};

#endif
