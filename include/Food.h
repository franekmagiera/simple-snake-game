#ifndef FOOD_H_
#define FOOD_H_

#include <SFML/Graphics.hpp>

class Food {
private:
    sf::RectangleShape rectangle; 
    bool isThereFood;
public:
    Food(); 
    void generateRandomPosition();
    const sf::Vector2f & getPosition() const { return rectangle.getPosition(); }
    const sf::RectangleShape & getRectangle() const { return rectangle; }
    bool getIsThereFood() const { return isThereFood; }
    void setIsThereFood(bool b) { isThereFood = b; }
};

#endif
