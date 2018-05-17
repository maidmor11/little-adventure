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
};

#endif
