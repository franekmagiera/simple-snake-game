#include "Snake.h"
#include "Constants.h"
#include <SFML/Graphics.hpp>

Snake::Snake()
{
    sf::RectangleShape r;
    sf::Vector2f v(size, size);
    r.setSize(v);
    v.x = width/2;
    v.y = height/2;
    r.setPosition(v);
    d.push_back(r);
    v.x -= size;
    r.setPosition(v);
    d.push_back(r);
    v.x -=size;
    r.setPosition(v);
    d.push_back(r);
    direction = Direction::right;
}

void Snake::grow()
{
    sf::RectangleShape r1, r2, r3;
    sf::Vector2f v(size, size);
    r3.setSize(v);
    r1 = *(d.end() - 1);
    r2 = *(d.end() - 2);
    if (r1.getPosition().x == r2.getPosition().x) {
        v.x = r1.getPosition().x;
        v.y = (r1.getPosition().y > r2.getPosition().y) ? (r1.getPosition().y + size) : (r1.getPosition().y - size); 
    }
    if (r1.getPosition().y == r2.getPosition().y) {
        v.y = r1.getPosition().y;
        v.x = (r1.getPosition().x > r2.getPosition().x) ? (r1.getPosition().x + size) : (r1.getPosition().x - size);
    }
    r3.setPosition(v);
    d.push_back(r3);
}

void Snake::move()
{
    d.pop_back();
    sf::RectangleShape newHead = d[0];
    sf::Vector2f v = newHead.getPosition();
    switch(direction)
    {
        case Direction::left :
                                v.x -= size;
                                break;
        case Direction::right :
                                v.x += size;
                                break;
        case Direction::up :
                                v.y -= size;
                                break;
        case Direction::down :
                                v.y += size;
                                break;
        default :
                                break;
    }
    newHead.setPosition(v);
    d.push_front(newHead);
}

bool Snake::touchesItself() const
{
   for (auto it = d.begin()+1; it != d.end(); it++ )
       if ((*it).getPosition() == d[0].getPosition())
           return true;
   return false;
}
