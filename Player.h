#ifndef PLAYER_H
#define PLAYER_H
#include <fstream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Player
{
public:
//------------------------------------------------------------------------------
  enum gender
  {
    MALE,
    FEMALE
  };

  enum race
  {
    HUMAN
  };
  enum classes
  {
    WIZARD
  };
//------------------------------------------------------------------------------

  Player();
  Player(std::string player_file);


  void setGender(gender new_gender);
  void setRace(race new_race);
  void setTexture(sf::Texture new_texture);
  void setClass(classes new_class);
  void addAbility(std::string new_ability);

  int getGender() { return gender_;};
  int getRace() { return race_;};
  int getClass() { return class_;};
  std::vector<std::string> getAbilityList() { return abilities_;};
  sf::Sprite getPlayerSprite() { return player_sprite_;};

private:
  //Player looks and settings
  sf::Texture player_texture_;
  sf::Sprite player_sprite_;

  gender gender_;
  race race_;
  classes class_;
  std::vector<std::string> abilities_;
};
#endif
