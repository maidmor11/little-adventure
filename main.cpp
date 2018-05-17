#include <SFML/Graphics.hpp>
#include <iostream>
#include "Room.h"
#include <vector>
int main()
{
  std::vector<State*> rooms;
  rooms.push_back(new Menu);
  rooms.push_back(new Arena);
  int current_room = State::MENU;

  sf::RenderWindow window(sf::VideoMode(640, 480), "Adventure");
  sf::Texture t1;
  t1.loadFromFile("./plant01.png");
  sf::Sprite s1(t1);
  while(window.isOpen())
  {
    window.clear();
    sf::Event e;
    int new_room = rooms.at(current_room)->transition();
    if(current_room != new_room)
    {
      rooms.at(current_room)->exit();
      current_room = new_room;
      rooms.at(current_room)->enter();
    }
    while(window.pollEvent(e))
    {
      if(e.type == sf::Event::Closed)
      {
        window.close();
      }
    }
    s1.setPosition(100 , 15);
    window.draw(s1);
    window.display();
  }
}
