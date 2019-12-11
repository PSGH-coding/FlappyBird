#include "../include/Tube.hpp"

Tube::Tube(Textures & t): textures(t), clock(){
  long_sprite = textures.get_ciel().getSize().x;
  larg_sprite = textures.get_ciel().getSize().y;
  }

vector<sf::Sprite> Tube::get_sprites(void) {return sprites;}

void Tube::crea_destr_tube(void){
  if (clock.getElapsedTime().asSeconds() > VIT_APPARITION_TUBE){
    clock.restart();
    crea_tube();
  }
  move_tube();
  destr_tube();
}

void Tube::move_tube(void){
  for (unsigned long int i = 0; i < sprites.size(); i++){
    float x = sprites[i].getPosition().x;
    float y = sprites[i].getPosition().y;
    sprites[i].setPosition(x - SCROLL_SPEED, y);
  }
}

void Tube::destr_tube(void){
  for (unsigned long int i = 0; i < sprites.size(); i++){
    if (sprites[i].getPosition().x < -200){
      sprites.erase(sprites.begin() + i);
    }
  }
}

void Tube::crea_tube(void){
  sf::Sprite ciel;
  sf::Sprite sol;
  ciel.setTexture(textures.get_ciel());
  sol.setTexture(textures.get_sol());
  int a = rand_a_b(0,5);

  switch(a){
    case 0:
      ciel.setPosition(1500, -550);
      sol.setPosition(1500, 400);
      break;

    case 1:
      ciel.setPosition(1500, -450);
      sol.setPosition(1500, 500);
      break;

    case 2:
      ciel.setPosition(1500, -350);
      sol.setPosition(1500, 600);
      break;

    case 3:
      ciel.setPosition(1500, -250);
      sol.setPosition(1500, 700);
      break;

    case 4:
      ciel.setPosition(1500, -150);
      sol.setPosition(1500, 800);
      break;
  }
  sprites.push_back(ciel);
  sprites.push_back(sol);
}

int Tube::rand_a_b(int a, int b){
  return rand()%(b-a) + a;
}

sf::Sprite Tube::get_sprite(int i) {return sprites[i];}
float Tube::get_long(void) {return long_sprite;}
float Tube::get_larg(void) {return larg_sprite;}
