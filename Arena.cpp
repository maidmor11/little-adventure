#include "Arena.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


void Arena::enter(Engine* engine)
{
  this->room_sprite_vector_.clear();
  arena_background_.loadFromFile("./assets/arena_background.png");
  background_sprite_.setTexture(arena_background_);
  this->room_sprite_vector_.push_back(background_sprite_);
  engine->setSpriteVector(this->room_sprite_vector_);
  std::cout << "Entered Arena" << std::endl;
}

void Arena::exit()
{
  std::cout << "Exit Arena" << std::endl;
}

int Arena::transition(sf::RenderWindow* game_window)
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
