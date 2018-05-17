#include <SFML/Graphics.hpp>
#include <vector>
#include "Engine.h"
#include "Room.h"
#include <iostream>

Engine::Engine()
{

  window_.create(sf::VideoMode(600,400), "Adventure");
  fillRoomVector();
  this->sprite_vector_.clear();
}


void Engine::fillRoomVector()
{
  room_vector_.push_back(new Menu);
  room_vector_.push_back(new Arena);
}

void Engine::run()
{
  is_running_ = true;

  int current_room = State::current_room::MENU;
  int next_room = current_room;


  while(is_running_ == true && window_.isOpen())
  {
    window_.clear();
    sf::Event e;
    while(window_.pollEvent(e))
    {
      if(e.type == sf::Event::Closed)
        window_.close();
    }

    next_room = room_vector_.at(current_room)->transition();
    if(current_room != next_room)
    {
      room_vector_.at(current_room)->exit();
      current_room = next_room;
      room_vector_.at(current_room)->enter(this);
    }

    drawSpriteVector(this->sprite_vector_);
    window_.display();
  }
}

void Engine::drawSpriteVector(std::vector<sf::Sprite> sprite_vector)
{
  for(auto &sprite : sprite_vector)
  {
    window_.draw(sprite);
  }
}

void Engine::setSpriteVector(std::vector<sf::Sprite> sprite_vector)
{
  this->sprite_vector_.clear();
  for(auto &sprite : sprite_vector)
  {
    this->sprite_vector_.push_back(sprite);
  }
}
