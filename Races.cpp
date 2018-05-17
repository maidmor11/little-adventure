#include <SFML/Graphics.hpp>
#include "Races.h"
#include "Engine.h"
#include <iostream>
#include <vector>

void Races::enter(Engine* engine)
{
  this->room_sprite_vector_.clear();
  human_banner_.loadFromFile("./assets/human_banner.png");
  human_banner_sprite_.setTexture(human_banner_);
  human_banner_sprite_.setPosition(1280/2, 960/2);
  this->room_sprite_vector_.push_back(human_banner_sprite_);
  engine->setSpriteVector(this->room_sprite_vector_);
  std::cout << "Entered Races" << std::endl;
}

void Races::exit()
{
  std::cout << "Exit Races" << std::endl;
}

int Races::transition(sf::RenderWindow* game_window)
{
  sf::Vector2i mouse_pos = sf::Mouse::getPosition(*game_window);
  if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
  {
    if(human_banner_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
      return State::current_room::CHOOSE_CLASS;
  }
}
