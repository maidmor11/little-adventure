#include <SFML/Graphics.hpp>
#include "Create_character.h"
#include "Engine.h"
#include "Player.h"

#include <iostream>
#include <vector>

void CreateCharacter::enter(Engine* engine)
{
  this->room_sprite_vector_.clear();

  gender_male_.loadFromFile("./assets/gender_male.png");
  gender_male_sprite_.setTexture(gender_male_);
  gender_male_sprite_.setPosition(1280-426, 0);

  gender_female_.loadFromFile("./assets/gender_female.png");
  gender_female_sprite_.setTexture(gender_female_);
  gender_female_sprite_.setPosition(426, 0);

  human_banner_.loadFromFile("./assets/human_banner.png");
  human_banner_sprite_.setTexture(human_banner_);
  human_banner_sprite_.setPosition(1280-800, 200);

  wizard_banner_.loadFromFile("./assets/wizard_banner.png");
  wizard_banner_sprite_.setTexture(wizard_banner_);
  wizard_banner_sprite_.setPosition(1280-800, 400);

  fire_ability_banner_.loadFromFile("./assets/fire_ability_banner.png");
  fire_ability_banner_sprite_.setTexture(fire_ability_banner_);
  fire_ability_banner_sprite_.setPosition(1280-426, 600);

  ice_ability_banner_.loadFromFile("./assets/ice_ability_banner.png");
  ice_ability_banner_sprite_.setTexture(ice_ability_banner_);
  ice_ability_banner_sprite_.setPosition(426, 600);

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
  bool setted_gender = false;
  bool setted_race = false;
  bool setted_class = false;
  bool setted_ability = false;
  sf::Vector2i mouse_pos = sf::Mouse::getPosition(*game_window);
  if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
  {
    if(gender_male_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)) && !setted_gender)
      {
        player_->setGender(Player::gender::MALE);
        setted_gender = true;
      }
    if(gender_female_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)) && !setted_gender)
    {
      player_->setGender(Player::gender::FEMALE);
      setted_gender = true;
    }

    if(human_banner_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)) && !setted_race)
    {
      player_->setRace(Player::race::HUMAN);
      setted_race = true;
    }

    if(wizard_banner_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
    {
      player_->setClass(Player::classes::WIZARD);
      setted_class = true;
    }

    if(fire_ability_banner_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)) && !setted_ability)
    {
      player_->addAbility("Fire MAge");
      setted_ability = true;
    }

    if(ice_ability_banner_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)) && !setted_ability)
    {
      player_->addAbility("Ice Mage");
      setted_ability = true;
    }

    if(setted_gender && setted_race && setted_class && setted_ability)
    {
        return State::current_room::ARENA;
    }
  }
  return State::current_room::CREATE_CHARACTER;

}
