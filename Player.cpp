#include "Player.h"

Player::Player()
{

}

Player::Player(std::string player_file)
{

}


void Player::setGender(gender new_gender)
{
  gender_ = new_gender;
}

void Player::setRace(race new_race)
{
  race_ = new_race;
}

void Player::setTexture(std::string new_texture)
{
  player_texture_.loadFromFile(new_texture);
  player_sprite_.setTexture(player_texture_);
}

void Player::setClass(classes new_class)
{
  class_ = new_class;
}

void Player::addAbility(std::string new_ability)
{
  abilities_.push_back(new_ability);
}
