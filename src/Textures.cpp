#include "../include/Textures.hpp"

Textures::Textures(){
  tex_bird.loadFromFile("./images/bird.png");
  tube_sol.loadFromFile("./images/Tube_sol.png");
  tube_ciel.loadFromFile("./images/Tube_ciel.png");
  background.loadFromFile("./images/Background.png");
  background2.loadFromFile("./images/Background2.png");
  tex_sol.loadFromFile("./images/sol.png");
  rect_gris.loadFromFile("./images/rectangle_gris.png");
}

sf::Texture & Textures::get_bird(void){return tex_bird;}
sf::Texture & Textures::get_sol(void){return tube_sol;}
sf::Texture & Textures::get_ciel(void){return tube_ciel;}
sf::Texture & Textures::get_background(void){return background;}
sf::Texture & Textures::get_background2(void){return background2;}
sf::Texture & Textures::get_tex_sol(void){return tex_sol;}
sf::Texture & Textures::get_rect_gris(void){return rect_gris;}
