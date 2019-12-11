#include <fstream>
#include <math.h>
#include "Musique.hpp"
#include "Fond.hpp"
#include "Tube.hpp"
#include "Fin_jeu.hpp"
#include "Textures.hpp"
#include "Bird.hpp"
#include "Texte.hpp"
#include "Touches.hpp"

#define JUMP_POWER -6


class Game{
  private:
    sf::RenderWindow window;
    Touches touches;
    Textures textures;
    Bird bird;
    Tube tube;
    Fond fond;
    Texte texte;
    bool start;
    bool end;
    Musique musique;
    Fin_jeu fin;

  public:
    Game():
      window(sf::VideoMode(WINDOW_LONG, WINDOW_HAUT), "Flappy Bird"),
      touches(),
      textures(),
      bird(textures),
      tube(textures),
      fond(textures),
      texte(),
      start(false),
      end(false),
      musique(),
      fin(textures)
    {}

    Textures get_textures(void) {return textures;}

    void Ouverture(int tab[NBR_SAVES]);

    void Fermeture(int tab[NBR_SAVES]);

    void Compare(int tab[NBR_SAVES]);

    void sauvegarde(void);

    void Update_score(void);

    void Check_collision(void);

    void Move_fond();

    void Move_tube();

    void Move_bird();

    void Check_hauteur();

    void ProcessEvents();

    void Check_key(sf::Event & event, bool valeur);

    void Render();

    void run();
};
