#include "Classes.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


void Classes::enter(Engine* engine)
{
  this->room_sprite_vector_.clear();

  wizard_banner_.loadFromFile("./assets/wizard_banner.png");
  wizard_banner_sprite_.setTexture(wizard_banner_);
  wizard_banner_sprite_.setPosition(1280/2, 960/2);

  this->room_sprite_vector_.push_back(wizard_banner_sprite_);
  engine->setSpriteVector(this->room_sprite_vector_);
  std::cout << "Entered Classes" << std::endl;
}

void Classes::exit()
{
  std::cout << "Exit Classes" << std::endl;
}

int Classes::transition(sf::RenderWindow* game_window)
{
  sf::Vector2i mouse_pos = sf::Mouse::getPosition(*game_window);
  if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
  {
    if(wizard_banner_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
    {
      return State::current_room::CHOOSE_ABILITIES;
    }

  }
  return State::current_room::CHOOSE_CLASS;
}
