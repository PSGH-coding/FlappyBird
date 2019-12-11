#include "../include/Texte.hpp"

Texte::Texte(): points(0){
  font.loadFromFile("./images/Adventure.otf");

  score.setFont(font);
  score.setPosition(10,0);
  string scorestring = to_string(points);
  score.setString(scorestring);
  score.setCharacterSize(50);

  start.setFont(font);
  start.setOrigin(190,200);
  start.setPosition(WINDOW_LONG/2, WINDOW_HAUT/2);
  start.setString("START");
  start.setCharacterSize(150);

  press_key.setFont(font);
  press_key.setOrigin(100,40);
  press_key.setPosition(WINDOW_LONG/2, WINDOW_HAUT/2);
  press_key.setString("press spacebar");
  press_key.setCharacterSize(40);

  high_scores.setFont(font);
  high_scores.setOrigin(100,40);
  high_scores.setPosition(WINDOW_LONG/2 - 70, 200);
  high_scores.setString("HIGH SCORES");
  high_scores.setFillColor(sf::Color(0, 0, 0));
  high_scores.setCharacterSize(60);

  premier.setFont(font);
  premier.setOrigin(40,40);
  premier.setPosition(WINDOW_LONG/2 + 10, 300);
  premier.setFillColor(sf::Color(0, 0, 0));
  premier.setCharacterSize(50);

  deuxieme.setFont(font);
  deuxieme.setOrigin(40,40);
  deuxieme.setPosition(WINDOW_LONG/2 + 10, 370);
  deuxieme.setFillColor(sf::Color(0, 0, 0));
  deuxieme.setCharacterSize(50);

  troisieme.setFont(font);
  troisieme.setOrigin(40,40);
  troisieme.setPosition(WINDOW_LONG/2 + 10, 440);
  troisieme.setFillColor(sf::Color(0, 0, 0));
  troisieme.setCharacterSize(50);

  your_score.setFont(font);
  your_score.setOrigin(100,40);
  your_score.setPosition(WINDOW_LONG/2 - 20, 550);
  your_score.setString("Your score: ");
  your_score.setFillColor(sf::Color(0, 0, 0));
  your_score.setCharacterSize(50);
}

void Texte::update_score(void){
  points += 1;
  string scorestring = to_string(points);
  score.setString(scorestring);
}

sf::Text Texte::get_score(void) {return score;}
sf::Text Texte::get_start(void) {return start;}
sf::Text Texte::get_press_key(void) {return press_key;}
sf::Text Texte::get_high_scores(void) {return high_scores;}
sf::Text Texte::get_premier(void) {return premier;}
sf::Text Texte::get_deuxieme(void) {return deuxieme;}
sf::Text Texte::get_troisieme(void) {return troisieme;}
sf::Text Texte::get_your_score(void) {return your_score;}
int Texte::get_points(void) {return points;}

void Texte::set_valeurs(int tab[NBR_SAVES]){
  string valeur = to_string(tab[0]);
  premier.setString(valeur);

  valeur = to_string(tab[1]);
  deuxieme.setString(valeur);

  valeur = to_string(tab[2]);
  troisieme.setString(valeur);

  score.setCharacterSize(50);
  score.setFillColor(sf::Color(0, 0, 0));
  score.setPosition(WINDOW_LONG/2 - 25, 600);
}
