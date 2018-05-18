#include <SFML/Graphics.hpp>
#include "Create_character.h"
#include "Engine.h"
#include "Player.h"

#include <iostream>
#include <vector>

void CreateCharacter::enter(Engine* engine)
{
  this->room_sprite_vector.clear();

  gender_male_.loadFromFile("./assets/gender_male.png");
  gender_male_sprite_.setTexture(gender_male_);
  gender_male_sprite_.setPosition(1280-426, 20);

  gender_female_.loadFromFile("./assets/gender_female.png");
  gender_female_sprite_.setTexture(gender_female_);
  gender_female_sprite_.setPosition(426, 20);

  human_banner_.loadFromFile("./assets/human_banner.png");
  human_banner_sprite_.setTexture(human_banner_);
  human_banner_sprite_.setPosition(1280-800, 200);

  wizard_banner_.loadFromFile("./assets/wizard_banner.png");
  wizard_banner_sprite_.setTexture(wizard_banner_);
  wizard_banner_sprite_.setPosition(1280-800, 360);

  fire_ability_banner_.loadFromFile("./assets/fire_ability_banner.png");
  fire_ability_banner_sprite_.setTexture(fire_ability_banner_);
  fire_ability_banner_sprite_.setPosition(1280-426, 540);

  ice_ability_banner_.loadFromFile("./assets/ice_ability_banner.png");
  ice_ability_banner_sprite_.setTexture(ice_ability_banner_);
  ice_ability_banner_sprite_.setPosition(426, 540);

  this->room_sprite_vector_.push_back(gender_male_sprite_);
  this->room_sprite_vector_.push_back(gender_female_sprite_);
  this->room_sprite_vector_.push_back(human_banner_sprite_);
  this->room_sprite_vector_.push_back(wizard_banner_sprite_);
  this->room_sprite_vector_.push_back(fire_ability_banner_sprite_);
  this->room_sprite_vector_.push_back(ice_ability_banner_sprite_);

  engine->setSpriteVector(this->room_sprite_vector_);
  std::cout << "Enterd Create Character" << std::endl;

}

void CreateCharacter::exit()
{
  std::cout << "Exit Create Character" << std::endl;
}

int CreateCharacter::transition(sf::RenderWindow* game_window)
{
  sf::Vector2i mouse_pos = sf::Mouse::getPosition(*game_window);
  if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    return 0;


}
