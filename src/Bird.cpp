#include "../include/Bird.hpp"

Bird::Bird(Textures & textures): Vy(0){
  sprite.setTexture(textures.get_bird());
  long_sprite = textures.get_bird().getSize().x/2;
  larg_sprite = textures.get_bird().getSize().y/2;
  sprite.setOrigin(long_sprite, larg_sprite);
  sprite.setPosition(BIRD_POS_X, BIRD_POS_Y);
}

sf::Sprite & Bird::get_sprite(void) {return sprite;}
float Bird::get_Vy(void) {return Vy;}
float Bird::get_long(void) {return long_sprite;}
float Bird::get_larg(void) {return larg_sprite;}

void Bird::set_Vy(float i) {Vy = i;}

void Bird::move(void){
  float x = sprite.getPosition().x;
  float y = sprite.getPosition().y;
  Vy +=  GRAVITY;
  y += Vy;
  sprite.setPosition(x, y);
  set_rotation();
}

bool Bird::check_hauteur(void){
  float y = sprite.getPosition().y;
  if (y - (larg_sprite - 10) < 0 || y + (larg_sprite - 10) > 850){
    return true;
  }
  return false;
}

void Bird::set_rotation(void){
  if (Vy >= 0){
    sprite.setRotation(4*Vy);
  }
  else if (Vy < 0){
    sprite.setRotation(Vy);
  }
  if ((4 * Vy) > 90){
    sprite.setRotation(90);
  }
}
