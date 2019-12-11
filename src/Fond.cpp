#include "../include/Fond.hpp"

Fond::Fond(Textures & textures){
  long_sprite = textures.get_background().getSize().x * 1.5;
  long_sol = textures.get_tex_sol().getSize().x * 1.5;
  sprite.setTexture(textures.get_background());
  sprite.setScale(1.5,1.5);
  sprite2.setTexture(textures.get_background2());
  sprite2.setScale(1.5,1.5);
  sprite2.setPosition(long_sprite,0);
  sol.setTexture(textures.get_tex_sol());
  sol.setScale(1.5,1);
  sol.setPosition(0,820);
  sol2.setTexture(textures.get_tex_sol());
  sol2.setScale(1.5,1);
  sol2.setPosition(long_sol,820);
}

sf::Sprite Fond::get_sprite(void) {return sprite;}
sf::Sprite Fond::get_sprite2(void) {return sprite2;}
sf::Sprite Fond::get_sol(void) {return sol;}
sf::Sprite Fond::get_sol2(void) {return sol2;}

void Fond::move_fond(void){
  float x = sprite.getPosition().x;
  if (x < -long_sprite){
    sprite.setPosition(long_sprite - SCROLL_FOND,0);
    x = long_sprite - SCROLL_FOND;
  }
  sprite.setPosition(x - SCROLL_FOND, 0);

  x = sprite2.getPosition().x;
  if (x < -long_sprite){
    sprite2.setPosition(long_sprite - SCROLL_FOND,0);
    x = long_sprite - SCROLL_FOND;
  }
  sprite2.setPosition(x - SCROLL_FOND, 0);

  x = sol.getPosition().x;
  if (x < -long_sol){
    sol.setPosition(long_sol - SCROLL_SPEED,820);
    x = long_sol - SCROLL_SPEED;
  }
  sol.setPosition(x - SCROLL_SPEED, 820);

  x = sol2.getPosition().x;
  if (x < -long_sol){
    sol2.setPosition(long_sol- SCROLL_SPEED,820);
    x = long_sol - SCROLL_SPEED;
  }
  sol2.setPosition(x - SCROLL_SPEED, 820);
}
