#ifndef BIRD_HPP
#define BIRD_HPP
#include "Textures.hpp"

#define BIRD_POS_X 300
#define BIRD_POS_Y 300
#define GRAVITY 0.2

class Bird{
private:
  float Vy;
  float long_sprite;
  float larg_sprite;
  sf::Sprite sprite;
public:
  Bird(Textures & textures);

  sf::Sprite & get_sprite(void);
  float get_Vy(void);
  float get_long(void);
  float get_larg(void);

  void set_Vy(float i);

  void move(void);

  bool check_hauteur(void);

  void set_rotation(void);
};

#endif
