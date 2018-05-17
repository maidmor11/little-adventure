#include "Arena.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


void Gender::enter(Engine* engine)
{
  this->room_sprite_vector_.clear();

  engine->setSpriteVector(this->room_sprite_vector_);
  std::cout << "Entered Gender" << std::endl;
}

void Gender::exit()
{
  std::cout << "Exit Arena" << std::endl;
}

int Gender::transition(sf::RenderWindow* game_window)
{
  sf::Vector2i mouse_pos = sf::Mouse::getPosition(*game_window);
  if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
  {
    if(arena_give_up_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
    {
      return State::current_room::CHOOSE_RACE;
    }

  }
  return 1;
}
