#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>

class Engine;

class State
{
public:
  enum current_room
  {
    MENU,
    LOAD_SAFE_GAME,
    CREATE_CHARACTER,
    ARENA
  };
  virtual void enter(Engine* engine) = 0;
  virtual void exit() = 0;
  virtual int transition(sf::RenderWindow* game_window) = 0;
protected:
  // Engine* engine_;
  std::vector<sf::Sprite> room_sprite_vector_;
};
#endif
