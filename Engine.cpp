#include <SFML/Graphics.hpp>
#include <vector>
#include "Engine.h"
#include "Room.h"
#include <iostream>




//INCLUDE OF THE ROOMS:
#include "Menu.h"
#include "Arena.h"


Engine::Engine()
{
  window_.create(sf::VideoMode(1280,960), "Adventure");
  fillRoomVector();
  this->sprite_vector_.clear();
  current_room_ = State::current_room::MENU;
  next_room_ = current_room_;
  room_vector_.at(current_room_)->enter(this);
}


void Engine::fillRoomVector()
{
  room_vector_.push_back(new Menu);
  room_vector_.push_back(new Arena);
}

void Engine::run()
{
  is_running_ = true;


  while(is_running_ == true && window_.isOpen())
  {
    window_.clear();
    sf::Event e;
    while(window_.pollEvent(e))
    {
      if(e.type == sf::Event::Closed)
        window_.close();
    }
    handleRoom();

    drawSpriteVector(this->sprite_vector_);
    window_.display();
  }
}


void Engine::handleRoom()
{
  next_room_ = room_vector_.at(current_room_)->transition(&window_);
  if(current_room_ != next_room_)
  {
    room_vector_.at(current_room_)->exit();
    current_room_ = next_room_;
    room_vector_.at(current_room_)->enter(this);
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

void Engine::appendSpriteVector(std::vector<sf::Sprite> sprite_vector)
{
  for(auto &sprite : sprite_vector)
  {
    this->sprite_vector_.push_back(sprite);
  }
}
