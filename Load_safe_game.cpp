#include <SFML/Graphics.hpp>
#include "Load_safe_game.h"
#include "Engine.h"
#include "Player.h"
#include <iostream>
#include <fstream>

#include "Load_safe_game.h"

void Load::enter(Engine* engine)
{
  player_ = engine->getPlayer();
  this->room_sprite_vector_.clear();

  save_nr_1_.loadFromFile("./assets/save_nr_1.png");
  save_nr_1_sprite_.setTexture(save_nr_1_);
  save_nr_1_sprite_.setPosition(1280/2, 100);

  save_nr_2_.loadFromFile("./assets/save_nr_2.png");
  save_nr_2_sprite_.setTexture(save_nr_2_);
  save_nr_2_sprite_.setPosition(1280/2, 250);

  save_nr_3_.loadFromFile("./assets/save_nr_3.png");
  save_nr_3_sprite_.setTexture(save_nr_3_);
  save_nr_3_sprite_.setPosition(1280/2, 400);

  save_nr_4_.loadFromFile("./assets/save_nr_4.png");
  save_nr_4_sprite_.setTexture(save_nr_4_);
  save_nr_4_sprite_.setPosition(1280/2, 550);

  save_nr_5_.loadFromFile("./assets/save_nr_5.png");
  save_nr_5_sprite_.setTexture(save_nr_5_);
  save_nr_5_sprite_.setPosition(1280/2, 700);

  this->room_sprite_vector_.push_back(save_nr_1_sprite_);
  this->room_sprite_vector_.push_back(save_nr_2_sprite_);
  this->room_sprite_vector_.push_back(save_nr_3_sprite_);
  this->room_sprite_vector_.push_back(save_nr_4_sprite_);
  this->room_sprite_vector_.push_back(save_nr_5_sprite_);

  engine->setSpriteVector(this->room_sprite_vector_);
  std::cout << "Entered LOAD_SAFE_GAME" << std::endl;

}

void Load::exit()
{
  std::cout << "Exit LOAD_SAFE_GAME" << std::endl;
}

int Load::transition(sf::RenderWindow* game_window)
{

  sf::Vector2i mouse_pos = sf::Mouse::getPosition(*game_window);
  if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
  {
    if(save_nr_1_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
    {
      loadSaveGame(1);
      std::cout << "Picked 1st save" << std::endl;
      return State::current_room::ARENA;
    }
    if(save_nr_2_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
    {
      loadSaveGame(2);
      std::cout << "Picked second save" << std::endl;
      return State::current_room::ARENA;
    }

    if(save_nr_3_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
    {
      loadSaveGame(3);
      std::cout << "Picked third save" << std::endl;
      return State::current_room::ARENA;
    }

    if(save_nr_4_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
    {
      loadSaveGame(4);
      std::cout << "Picked fourth save" << std::endl;
      return State::current_room::ARENA;
    }

    if(save_nr_5_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
    {
      loadSaveGame(5);
      std::cout << "Picked fifth save" << std::endl;
      return State::current_room::ARENA;
    }
  }
  return State::current_room::LOAD_SAFE_GAME;
}

int Load::loadSaveGame(int save_nr)
{
  std::ifstream save_game;
  std::string read_string;

  save_game.open("./saves/save-game-" + std::to_string(save_nr) + ".save");
  if(!save_game.is_open())
  {
    return State::room_error::ERR_CAN_NOT_OPEN;
  }
  while(!save_game.eof())
  {
    save_game >> read_string;
    //Set Gender
    if(read_string == "Female")
      player_->setGender(Player::gender::FEMALE);
    if(read_string == "Male")
      player_->setGender(Player::gender::MALE);

    //Set Race
    if(read_string == "Human")
      player_->setRace(Player::race::HUMAN);

    //Set Class
    if(read_string == "Wizard")
      player_->setClass(Player::classes::WIZARD);

    //Set Ability
    if(read_string == "ABILITY:")
    {
      save_game >> read_string;
      player_->addAbility(read_string);
    }
  }
  save_game.close();
}
