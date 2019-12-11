#ifndef TUBE_HPP
#define TUBE_HPP
#include "Textures.hpp"

#define SCROLL_SPEED 2
#define VIT_APPARITION_TUBE 1.4

class Tube{
private:
  vector<sf::Sprite> sprites;
  float long_sprite;
  float larg_sprite;
  Textures textures;
  sf::Clock clock;
public:
  Tube(Textures & t);

  vector<sf::Sprite> get_sprites(void);

  void crea_destr_tube(void);

  void move_tube(void);

  void destr_tube(void);

  void crea_tube(void);

  int rand_a_b(int a, int b);

  sf::Sprite get_sprite(int i);
  float get_long(void);
  float get_larg(void);
};

#endif
