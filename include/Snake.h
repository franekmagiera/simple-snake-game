#ifndef SNAKE_H_
#define SNAKE_H_

#include "Constants.h"
#include <deque>
#include <SFML/Graphics.hpp>

class Snake {
private:
   std::deque<sf::RectangleShape> d; 
   Direction direction;
public:
    Snake();
    void move();
    void grow(const sf::Vector2f & newHead);
    void changeDirection(const Direction direction_) { direction = direction_; }
    Direction getDirection() const { return direction; }
    const sf::Vector2f & getHeadPosition() const { return d[0].getPosition(); }
    const std::deque<sf::RectangleShape> & getDeque() const { return d; }
    bool touchesItself() const;
};

#endif
