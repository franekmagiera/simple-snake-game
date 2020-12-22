#include "../include/Food.h"
#include "../include/Constants.h"
#include <random>

Food::Food()
{
    sf::Vector2f v(size, size);
    rectangle.setSize(v);
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(0, 0);
    isThereFood = false;
}

void Food::generateRandomPosition()
{
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> xPosition(1, width/size - 2);
   std::uniform_int_distribution<> yPosition(1, height/size - 2);
   rectangle.setPosition(xPosition(gen)*size, yPosition(gen)*size);
   setIsThereFood(true);
}
