#include "../include/Musique.hpp"

Musique::Musique(void){
  soundtrack.openFromFile("musiques/Soundtrack.ogg");
  soundtrack.setLoop(true);
}

void Musique::play(void) {soundtrack.play();}
void Musique::pause(void) {soundtrack.pause();}
