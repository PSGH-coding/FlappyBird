#ifndef TEXTE_HPP
#define TEXTE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

#define NBR_SAVES 10
#define WINDOW_LONG 1400
#define WINDOW_HAUT 900

class Texte{
private:
  sf::Font font;
  sf::Text score;
  sf::Text start;
  sf::Text press_key;
  sf::Text high_scores;
  sf::Text premier;
  sf::Text deuxieme;
  sf::Text troisieme;
  sf::Text your_score;
  int points;
public:
  Texte();

  void update_score(void);

  sf::Text get_score(void);
  sf::Text get_start(void);
  sf::Text get_press_key(void);
  sf::Text get_high_scores(void);
  sf::Text get_premier(void);
  sf::Text get_deuxieme(void);
  sf::Text get_troisieme(void);
  sf::Text get_your_score(void);
  int get_points(void);

  void set_valeurs(int tab[NBR_SAVES]);
};

#endif
