CFLAGS= -g -Wall -Wextra

bin/game: build/main.o build/player.o
	g++ build/main.o build/player.o -o bin/game -lsfml-graphics -lsfml-window -lsfml-system $(CFLAGS)

build/main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o $(CFLAGS)

build/player.o: src/player.cpp src/player.cpp
	g++ -c src/player.cpp -o build/player.o $(CFLAGS)

.PHONY: all clean run

all:
	make
	make run

clean:
	rm build/*

run:
	bin/game
