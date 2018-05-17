#include "Arena.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


void Gender::enter(Engine* engine)
{
  this->room_sprite_vector_.clear();
  gender_male_.loadFromFile("./assets/gender_male.png");
  gender_female_.loadFromFile("./assets/gender_female.png");

  gender_male_sprite_.setTexture(gender_male_);
  gender_female_sprite_.setTexture(gender_female_);


  gender_male_sprite.setPosition(1280 / 2 + 100, 960 / 2);
  gender_female_sprite_.setPosition(1280 / 2 - 100, 960 / 2);

  this->room_vector_.push_back(gender_male_sprite_);
  this->room_vector_.push_back(gender_female_sprite_);

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
    if(gender_male_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
    {
      return State::current_room::CHOOSE_RACE;
    }
    if(gender_female_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
    {
      return State::current_room::CHOOSE_RACE;
    }

  }
  return State::current_room::CHOOSE_GENDER;
}
