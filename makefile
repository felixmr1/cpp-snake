CFLAGS= -g -Wall -Wextra

bin/game: build/main.o build/snake.o
	g++ build/main.o build/snake.o -o bin/game -lsfml-graphics -lsfml-window -lsfml-system $(CFLAGS)

build/main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o $(CFLAGS)

build/snake.o: src/snake.cpp
	g++ -c src/snake.cpp -o build/snake.o $(CFLAGS)

.PHONY: all clean run

all:
	make
	make run

clean:
	rm build/*

run:
	bin/game
