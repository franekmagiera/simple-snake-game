#ifndef GAME_H_
#define GAME_H_

#include "Snake.h"
#include "Food.h"
#include "Constants.h"

class Game {
private:
    Snake snake;
    Food food;
    bool gameOver = false;
    int score = 0;
    int sleepTime = 100; // in milliseconds
public:
    Game() {}
    void mainLoopBody(Direction newDir); 
    bool isGameOver() { return gameOver; }
    const Snake & getSnake() const { return snake; }
    const Food & getFood() const { return food; }
    int getScore() const { return score; }
    int getSleepTime() const { return sleepTime; }
};

#endif
