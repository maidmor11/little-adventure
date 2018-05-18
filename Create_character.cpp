#include <SFML/Graphics.hpp>
#include "Create_character.h"
#include "Engine.h"
#include "Player.h"

#include <iostream>
#include <fstream>
#include <vector>

void CreateCharacter::enter(Engine* engine)
{
  savegame_nr_ = 0;
  this->room_sprite_vector_.clear();
  player_ = engine->getPlayer();

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
  std::cout << "Entered Create Character" << std::endl;

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
  bool cancel = false;
  if(!canCreateNewSaveGame())
  {
    return State::room_error::ERR_NO_SAVE_LEFT;
  }

  std::ofstream new_save_file("./saves/save-game-" + std::to_string(savegame_nr_) + ".save");
  if(!new_save_file.is_open())
  {
    return State::room_error::ERR_CAN_NOT_OPEN;
  }

  do
  {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*game_window);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
      if(gender_male_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)) && !setted_gender)
      {
        std::cout << "Chose male" << std::endl;
        player_->setGender(Player::gender::MALE);
        new_save_file << "GENDER: Male" << std::endl;
        setted_gender = true;
      }
      if(gender_female_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)) && !setted_gender)
      {
        player_->setGender(Player::gender::FEMALE);
        setted_gender = true;
        new_save_file << "GENDER: Female" << std::endl;
        std::cout << "Chose female" << std::endl;
      }

      if(human_banner_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)) && !setted_race)
      {
        player_->setRace(Player::race::HUMAN);
        setted_race = true;
        new_save_file << "RACE: Human" << std::endl;
        std::cout << "Chose human" << std::endl;
      }

      if(wizard_banner_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)) && !setted_class)
      {
        player_->setClass(Player::classes::WIZARD);
        setted_class = true;
        new_save_file << "CLASS: Wizard" << std::endl;
        std::cout << "Chose wizard" << std::endl;
      }

      if(fire_ability_banner_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)) && !setted_ability)
      {
        player_->addAbility("Fire MAge");
        setted_ability = true;
        new_save_file << "ABILITY: Fire" << std::endl;
        std::cout << "Chose fire" << std::endl;
      }

      if(ice_ability_banner_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)) && !setted_ability)
      {
        player_->addAbility("Ice Mage");
        setted_ability = true;
        new_save_file << "ABILITY: Ice" << std::endl;
        std::cout << "Chose ice" << std::endl;
      }
      if(setted_gender && setted_race && setted_class && setted_ability)
      {
          new_save_file.close();
          return State::current_room::ARENA;
      }
    }
  }while(!cancel);
  return State::current_room::CREATE_CHARACTER;
}


bool CreateCharacter::canCreateNewSaveGame()
{
  std::string save = "./saves/save-game-";
  std::ifstream save_file;
  bool can_save = true;
  for(int savegame = 1; savegame < 5; savegame++)
  {
    save = "./saves/save-game-" + std::to_string(savegame) + ".save";
    save_file.open(save);
    if(save_file.good())
    {
      save_file.close();
      can_save = false;
    }
    else
    {
      savegame_nr_ = savegame;
      can_save = true;
      save_file.close();
      break;
    }
  }
  return can_save;
}
