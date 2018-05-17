#include "Room.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine.h"

void Menu::enter(Engine* engine)
{
  this->room_sprite_vector_.clear();
  plant_.loadFromFile("./plant01.png");
  plant_sprite_.setTexture(plant_);
  this->room_sprite_vector_.push_back(plant_sprite_);
  engine->setSpriteVector(this->room_sprite_vector_);
  std::cout << "Entered Menu" << std::endl;
}

void Menu::exit()
{
  std::cout << "Exit Menu" << std::endl;
}

int Menu::transition()
{
  int x;
  std::cin >> x;
  switch(x)
  {
    case MENU:
      return current_room::MENU;
    case ARENA:
      return current_room::ARENA;
    default:
      return current_room::MENU;
  }
}


void Arena::enter(Engine* engine)
{
  this->room_sprite_vector_.clear();
  engine->setSpriteVector(this->room_sprite_vector_);
  std::cout << "Entered Arena" << std::endl;
}

void Arena::exit()
{
  std::cout << "Exit Arena" << std::endl;
}

int Arena::transition()
{
  int x;
  std::cin >> x;
  switch(x)
  {
    case MENU:
      return current_room::MENU;
    case ARENA:
      return current_room::ARENA;
    default:
      return current_room::MENU;
  }
}
