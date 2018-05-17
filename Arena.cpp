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

  arena_give_up_.loadFromFile("./assets/arena_give_up_btn.png");
  arena_give_up_sprite_.setTexture(arena_give_up_);
  arena_give_up_sprite_.setPosition(1100, 850);

  this->room_sprite_vector_.push_back(background_sprite_);
  this->room_sprite_vector_.push_back(arena_give_up_sprite_);
  engine->setSpriteVector(this->room_sprite_vector_);
  std::cout << "Entered Arena" << std::endl;
}

void Arena::exit()
{
  std::cout << "Exit Arena" << std::endl;
}

int Arena::transition(sf::RenderWindow* game_window)
{
  sf::Vector2i mouse_pos = sf::Mouse::getPosition(*game_window);
  if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
  {
    if(arena_give_up_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
    {
      return State::MENU;
    }

  }
  return 1;
}
