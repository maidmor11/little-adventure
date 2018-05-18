#ifndef CREATE_CHAR_H
#define CREATE_CHAR_H
#include "Room.h"

class Player;

class CreateCharacter : public State
{
public:
  void enter(Engine* engine);
  void exit();
  int transition(sf::RenderWindow* game_window);
private:
  //Choose Gender
  sf::Texture gender_male_;
  sf::Sprite gender_male_sprite_;

  sf::Texture gender_female_;
  sf::Sprite gender_female_sprite_;

  //Choose Race
  sf::Texture human_banner_;
  sf::Sprite human_banner_sprite_;

  //Choose Class
  sf::Texture wizard_banner_;
  sf::Sprite wizard_banner_sprite_;

  //Choose Abilities
  sf::Texture fire_ability_banner_;
  sf::Texture ice_ability_banner_;

  sf::Sprite fire_ability_banner_sprite_;
  sf::Sprite ice_ability_banner_sprite_;


  int savegame_nr_;
  bool canCreateNewSaveGame();
  Player* player_;
};
#endif
