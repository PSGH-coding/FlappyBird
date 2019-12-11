#ifndef FINJEU_HPP
#define FINJEU_HPP
#include "Textures.hpp"

#define WINDOW_LONG 1400
#define WINDOW_HAUT 900

class Fin_jeu{
private:
  sf::Sprite rect_gris;

public:
  Fin_jeu(Textures & textures);

  sf::Sprite & get_rect_gris(void);

};

#endif
