#ifndef TEXTURES_HPP
#define TEXTURES_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Textures{
private:
  sf::Texture tex_bird;
  sf::Texture tube_sol;
  sf::Texture tube_ciel;
  sf::Texture background;
  sf::Texture background2;
  sf::Texture tex_sol;
  sf::Texture rect_gris;
public:
  Textures();

  sf::Texture & get_bird(void);
  sf::Texture & get_sol(void);
  sf::Texture & get_ciel(void);
  sf::Texture & get_background(void);
  sf::Texture & get_background2(void);
  sf::Texture & get_tex_sol(void);
  sf::Texture & get_rect_gris(void);
};

#endif
