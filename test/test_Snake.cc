#include "../include/Snake.h"
#include "../include/Constants.h"
#include <gtest/gtest.h>

TEST(SnakeTest, InitializationTest)
{
    Snake snake;
    EXPECT_EQ(snake.getDirection(), Direction::right);
    EXPECT_EQ(snake.getHeadPosition().x, width/2);
    EXPECT_EQ(snake.getHeadPosition().y, height/2);
}

TEST(SnakeTest, MoveTest)
{
    Snake snake;
    sf::Vector2f headPosition = snake.getHeadPosition();
    snake.move();
    EXPECT_EQ(snake.getHeadPosition().x, width/2 + size); 
    EXPECT_EQ(snake.getHeadPosition().y, headPosition.y);
    snake.changeDirection(Direction::up);
    snake.move();
    EXPECT_EQ(snake.getHeadPosition().x, width/2 + size); 
    EXPECT_EQ(snake.getHeadPosition().y, headPosition.y - size);
}

TEST(SnakeTest, GrowTest)
{
    Snake snake;
    sf::Vector2f v(width/2 + size, height/2);
    snake.grow();
    EXPECT_EQ(snake.getHeadPosition().x, width/2);
    EXPECT_EQ(snake.getHeadPosition().y, height/2);
}
