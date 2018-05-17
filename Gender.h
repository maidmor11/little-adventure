#ifndef ARENA_H
#define ARENA_H
#include "Room.h"

class Engine;
class Gender : public State
{
public:
  void enter(Engine* engine);
  void exit();
  int transition(sf::RenderWindow* game_window);
private:
  //Banners
  sf::Texture gender_male_;
  sf::Sprite gender_male_sprite_;

  sf::Texture gender_female_;
  sf::Sprite gender_female_sprite_;
};

#endif
