#ifndef ARENA_H
#define ARENA_H
#include "Room.h"

class Engine;
class Arena : public State
{
public:
  void enter(Engine* engine);
  void exit();
  int transition(sf::RenderWindow* game_window);
private:
  //Background Image
  sf::Texture arena_background_;
  sf::Sprite background_sprite_;
};

#endif
