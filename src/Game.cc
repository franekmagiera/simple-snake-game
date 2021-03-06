#include "../include/Game.h"
#include <SFML/Graphics.hpp>

void Game::mainLoopBody(Direction newDir)
{
    // check if snake's head touches the wall
    sf::Vector2f head = snake.getHeadPosition();
    if ((head.x == 0) ||
        (head.x == width - size) || 
        (head.y == 0) ||
        (head.y == height - size)) {
        gameOver = true;
        return;
    }
    // check if snake touches itself
    if (snake.touchesItself()) {
        gameOver = true;
        return;
    }
    // check if there's food and generate it if necessary
    if (!food.getIsThereFood())
        food.generateRandomPosition();
    // check if snake touches food and if he does he should grow
    sf::Vector2f foodPosition = food.getPosition();
    if (foodPosition.x == head.x && foodPosition.y == head.y) {
        snake.grow();
        score++;
        if (sleepTime > sleepTimeLowerLimit)
            sleepTime -= sleepTimeDecrement;
        food.setIsThereFood(false);
    }
    // if key was pressed change snake's direction
    if (newDir != Direction::none) 
        snake.changeDirection(newDir);
    snake.move();
}
