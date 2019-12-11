#include "../include/Game.hpp"

void Game::Ouverture(int tab[NBR_SAVES]){
  ifstream fichier("./scores/saves");
  if(fichier){
    for (int j = 0; j < NBR_SAVES; j++){
      fichier >> tab[j];
    }
  }
  else{
    cerr << "Erreur à l'ouverture !" << endl;
  }
  fichier.close();
}

void Game::Compare(int tab[NBR_SAVES]){
  int score = texte.get_points();
  for (int i = 0; i < NBR_SAVES; i++){
    if(score > tab[i]){
      for (int j = NBR_SAVES - 1; j > i; j--){
        tab[j] = tab[j - 1];
      }
      tab[i] = score;
      break;
    }
  }
}

void Game::Fermeture(int tab[NBR_SAVES]){
  ofstream fichier("./scores/saves");
  if(fichier){
    for (int j = 0; j < NBR_SAVES; j++){
      fichier << tab[j] << endl;
    }
    texte.set_valeurs(tab);
  }
  else{
    cerr << "Erreur à l'ouverture !" << endl;
  }
  fichier.close();
}


void Game::sauvegarde(void){
  int tab[NBR_SAVES];
  Ouverture(tab);
  Compare(tab);
  Fermeture(tab);
}

void Game::Update_score(void){
  for(long unsigned int i = 0; i < tube.get_sprites().size(); i ++){
    if (tube.get_sprite(i).getPosition().x < BIRD_POS_X
     && tube.get_sprite(i).getPosition().x + SCROLL_SPEED >= BIRD_POS_X){
       texte.update_score();
       break;
     }
  }
}

void Game::Check_collision(void){
  float long_bird = bird.get_long() - 5;
  float larg_bird = bird.get_larg() - 5;
  float long_tube = tube.get_long();
  float larg_tube = tube.get_larg();
  for(long unsigned int i = 0; i < tube.get_sprites().size(); i ++){
    if (BIRD_POS_X + long_bird > tube.get_sprite(i).getPosition().x
     && BIRD_POS_X - long_bird < tube.get_sprite(i).getPosition().x + long_tube
     && bird.get_sprite().getPosition().y + larg_bird > tube.get_sprite(i).getPosition().y
     && bird.get_sprite().getPosition().y - larg_bird < tube.get_sprite(i).getPosition().y + larg_tube){
       sauvegarde();
       //window.close();
       start = false;
       end = true;
     }
  }
}

void Game::Move_bird(){
  bird.move();
}

void Game::Move_tube(){
  tube.crea_destr_tube();
}

void Game::Move_fond(){
  fond.move_fond();
}

void Game::Check_hauteur(){
    if (bird.check_hauteur()){
      sauvegarde();
      //window.close();
      start = false;
      end = true;
    }
}

void Game::ProcessEvents(){
  sf::Event event;
  while (window.pollEvent(event)){
    if (event.type == sf::Event::Closed) window.close();
    else if (event.type == sf::Event::KeyPressed && !start && !end) {start = true;}
    else if (event.type == sf::Event::KeyPressed) Check_key(event, false);
    else if (event.type == sf::Event::KeyReleased) Check_key(event, true);
  }
}
void Game::Check_key(sf::Event & event, bool valeur){
  if (event.key.code == sf::Keyboard::Space) {
    if (touches.get_space() == true){
      bird.set_Vy(JUMP_POWER);
    }
    touches.set_space(valeur);
  }
}

void Game::Render(){
  window.clear();
  window.draw(fond.get_sprite());
  window.draw(fond.get_sprite2());
  window.draw(bird.get_sprite());
  for(long unsigned int i = 0; i < tube.get_sprites().size(); i ++){
    window.draw(tube.get_sprite(i));
  }
  if (start){
    window.draw(texte.get_score());
  }
  else if(end){
    window.draw(fin.get_rect_gris());
    window.draw(texte.get_high_scores());
    window.draw(texte.get_premier());
    window.draw(texte.get_deuxieme());
    window.draw(texte.get_troisieme());
    window.draw(texte.get_your_score());
    window.draw(texte.get_score());
  }
  else{
    window.draw(texte.get_start());
    window.draw(texte.get_press_key());
  }
  window.draw(fond.get_sol());
  window.draw(fond.get_sol2());
  window.display();
}

void Game::run(){
  musique.play();
  srand(time(NULL));
  sf::Image icon;
  if( !icon.loadFromFile("./images/bird.png")){
    exit(EXIT_FAILURE);
  }
  window.setIcon(90,64, icon.getPixelsPtr());
  window.setFramerateLimit(120);

  while (window.isOpen()){
    ProcessEvents();
    if(start){
      Move_tube();
      Move_fond();
      Move_bird();
      Check_hauteur();
      Check_collision();
      Update_score();
    }
    Render();
  }
}
