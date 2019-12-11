#include "../include/Fin_jeu.hpp"

Fin_jeu::Fin_jeu(Textures & textures){
  rect_gris.setTexture(textures.get_rect_gris());
  rect_gris.setOrigin(textures.get_rect_gris().getSize().x/2,textures.get_rect_gris().getSize().y/2);
  rect_gris.setPosition(WINDOW_LONG/2,WINDOW_HAUT/2);
  rect_gris.setScale(0.8,0.8);
  rect_gris.setColor(sf::Color(255, 255, 255, 180));
}

sf::Sprite & Fin_jeu::get_rect_gris(void) {return rect_gris;}
