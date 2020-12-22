all: snake-game run-test

snake-game: Food.o Game.o main.o Snake.o
		g++ Food.o Game.o main.o Snake.o -o snake-game -lsfml-graphics -lsfml-window -lsfml-system

run-test: src/Food.cc src/Game.cc src/main.cc src/Snake.cc test/gtest_main.cc test/test_Food.cc test/test_Game.cc test/test_Snake.cc
		g++ -Wall -pthread src/Food.cc src/Game.cc src/Snake.cc test/gtest_main.cc test/test_Food.cc test/test_Game.cc test/test_Snake.cc -lgtest_main -lgtest -lpthread -lsfml-graphics -lsfml-window -lsfml-system -o run-test

Food.o: src/Food.cc
		g++ -c src/Food.cc

Game.o: src/Game.cc
		g++ -c src/Game.cc

main.o: src/main.cc
		g++ -c src/main.cc

Snake.o: src/Snake.cc
		g++ -c src/Snake.cc

clean:
		rm Food.o Game.o main.o Snake.o

.PHONY: all