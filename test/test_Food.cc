#include "../include/Food.h"
#include "../include/Constants.h"
#include <gtest/gtest.h>

TEST(FoodTest, InitializationTest)
{
    Food food;
    EXPECT_EQ(food.getPosition().x, 0);
    EXPECT_EQ(food.getPosition().y, 0);
    EXPECT_EQ(food.getIsThereFood(), false);
}

TEST(FoodTest, GeneratePositionTest)
{
    Food food;
    food.generateRandomPosition();
    EXPECT_LT(food.getPosition().x, width - size + 1);
    EXPECT_LT(food.getPosition().y, height - size + 1);
    EXPECT_GT(food.getPosition().x, -1);
    EXPECT_GT(food.getPosition().y, -1);
}

TEST(FoodTest, SetIsThereFoodTest)
{
    Food food;
    EXPECT_EQ(food.getIsThereFood(), false);
    food.setIsThereFood(true);
    EXPECT_EQ(food.getIsThereFood(), true);
}
