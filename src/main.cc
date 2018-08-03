#include "Game.h"
#include "Constants.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
   sf::RenderWindow window(sf::VideoMode(width, height), "Snake");
   sf::RectangleShape frame;
   frame.setSize(sf::Vector2f(width-2*size, height-2*size));
   frame.setOutlineColor(sf::Color::White);
   frame.setOutlineThickness(size);
   frame.setPosition(sf::Vector2f(size, size));
   frame.setFillColor(sf::Color::Transparent);
   Game game;
   while (window.isOpen()) { 
       if (game.isGameOver()) {
           window.close();
           continue;
       }
       Direction direction = Direction::none;
       sf::Event event;
       while (window.pollEvent(event)) {
           if (event.type == sf::Event::Closed)
               window.close();
           else if (event.type == sf::Event::KeyPressed) {
               switch (event.key.code) {
                   case sf::Keyboard::Up :
                       direction = Direction::up;
                       break;
                   case sf::Keyboard::Down :
                       direction = Direction::down;
                       break;
                   case sf::Keyboard::Left :
                       direction = Direction::left;
                       break;
                   case sf::Keyboard::Right :
                       direction = Direction::right;
                       break;
                   default :
                       break;
                   case sf::Keyboard::Escape :
                       window.close();
                       break;
               }
           }
       }
       game.mainLoopBody(direction);
       window.clear(sf::Color::Black);
       for (const auto & r : game.getSnake().getDeque())
           window.draw(r);
       window.draw(game.getFood().getRectangle());
       window.draw(frame);
       window.display();
       sf::sleep(sf::milliseconds(game.getSleepTime()));
   }
   std::cout << "Your score: " << game.getScore() << '\n';
   return 0;
}
