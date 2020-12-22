#include "../include/Game.h"
#include <gtest/gtest.h>

TEST(GameTest, GameTest)
{
    Game game;
    game.mainLoopBody(Direction::none);
    if (game.getFood().getIsThereFood() == true) {
        EXPECT_EQ(game.getSnake().getHeadPosition().x, width/2 + size);
    }
    EXPECT_EQ(game.isGameOver(), false);
}
