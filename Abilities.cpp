#include <SFML/Graphics.hpp>
#include "Abilities.h"
#include "Engine.h"
#include <iostream>
#include <vector>

void Abilities::enter(Engine* engine)
{
  this->room_sprite_vector_.clear();

  fire_ability_banner_.loadFromFile("./assets/fire_ability_banner_.png");
  ice_ability_banner_.loadFromFile("./assets/ice_ability_banner_.png");

  fire_ability_banner_sprite_.setTexture(fire_ability_banner_);
  ice_ability_banner_sprite_.setTexture(ice_ability_banner_)

  fire_ability_banner_sprite_.setPosition(1280-426, 960/2);
  ice_ability_banner_sprite_.setPosition(426, 960/2);

  this->room_sprite_vector_.push_back(fire_ability_banner_sprite_);
  this->room_sprite_vector_.pushback(ice_ability_banner_sprite_);
  
  engine->setSpriteVector(this->room_sprite_vector_);
  std::cout << "Entered Abilities" << std::endl;
}

void Abilities::exit()
{
  std::cout << "Exit Abilities" << std::endl;
}

int Abilities::transition(sf::RenderWindow* game_window)
{
  sf::Vector2i mouse_pos = sf::Mouse::getPosition(*game_window);
  if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
  {
    if(fire_ability_banner_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
      return State::current_room::Arena;
    if(ice_ability_banner_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
      return State::current_room::ARENA;
  }
}
