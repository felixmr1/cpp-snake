CFLAGS= -g -Wall -Wextra

bin/game: build/main.o build/snake.o build/food.o
	g++ build/* -o bin/game -lsfml-graphics -lsfml-window -lsfml-system $(CFLAGS)

build/main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o $(CFLAGS)

build/snake.o: src/snake.cpp
	g++ -c src/snake.cpp -o build/snake.o $(CFLAGS)

build/food.o: src/food.cpp
	g++ -c src/food.cpp -o build/food.o $(CFLAGS)

.PHONY: all clean run

all:
	make
	make run

clean:
	rm build/*

run:
	bin/game
