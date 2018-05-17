#ifndef ABILITIES_H
#define ABILITIES_H

#include "Room.h"
class Engine;

class Abilities : public State
{
public:
  void enter(Engine* engine);
  void exit();
  int transition(sf::RenderWindow* game_window);
private:
  //Objects in Room
  sf::Texture fire_ability_banner_;
  sf::Texture ice_ability_banner_;

  sf::Sprite fire_ability_banner_sprite_;
  sf::Sprite ice_ability_banner_sprite_;
};




#endif //ABIITIES_H
