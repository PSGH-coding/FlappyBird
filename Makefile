CC ?=g++
CFLAGS ?=-Wall -Wextra -Werror

main: main.o Textures.o Bird.o Fin_jeu.o Fond.o Musique.o Texte.o Tube.o Touches.o Game.o
	g++ $(CFLAGS) ./obj/main.o ./obj/Textures.o ./obj/Bird.o ./obj/Fin_jeu.o ./obj/Fond.o ./obj/Musique.o ./obj/Texte.o ./obj/Tube.o ./obj/Touches.o ./obj/Game.o -o ./bin/main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lrt


main.o: ./src/main.cc
	g++ $(CFLAGS) -o ./obj/main.o -c ./src/main.cc

Textures.o: ./src/Textures.cpp
	g++ $(CFLAGS) -o ./obj/Textures.o -c ./src/Textures.cpp

Bird.o: ./src/Bird.cpp
	g++ $(CFLAGS) -o ./obj/Bird.o -c ./src/Bird.cpp

Fin_jeu.o: ./src/Fin_jeu.cpp
	g++ $(CFLAGS) -o ./obj/Fin_jeu.o -c ./src/Fin_jeu.cpp

Fond.o: ./src/Fond.cpp
	g++ $(CFLAGS) -o ./obj/Fond.o -c ./src/Fond.cpp

Musique.o: ./src/Musique.cpp
	g++ $(CFLAGS) -o ./obj/Musique.o -c ./src/Musique.cpp

Texte.o: ./src/Texte.cpp
	g++ $(CFLAGS) -o ./obj/Texte.o -c ./src/Texte.cpp

Tube.o: ./src/Tube.cpp
	g++ $(CFLAGS) -o ./obj/Tube.o -c ./src/Tube.cpp

Touches.o: ./src/Touches.cpp
	g++ $(CFLAGS) -o ./obj/Touches.o -c ./src/Touches.cpp

Game.o: ./src/Game.cpp
	g++ $(CFLAGS) -o ./obj/Game.o -c ./src/Game.cpp

.PHONY: clean
clean:

	rm -rf ./obj/*.o
	rm -f ./bin/main
