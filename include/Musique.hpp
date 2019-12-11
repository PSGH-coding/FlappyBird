#ifndef MUSIQUE_HPP
#define MUSIQUE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;

class Musique{
private:
  sf::Music soundtrack;

public:
  Musique(void);

  void play(void);
  void pause(void);
};

#endif
