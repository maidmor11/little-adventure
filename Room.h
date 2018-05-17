#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>
class Engine;

class State
{
public:
  enum current_room {MENU, ARENA};
  virtual void enter(Engine* engine) = 0;
  virtual void exit() = 0;
  virtual int transition() = 0;
protected:
  // Engine* engine_;
  std::vector<sf::Sprite> room_sprite_vector_;
};

class Menu : public State
{
public:
  void enter(Engine* engine);
  void exit();
  int transition();
private:
  //Objects in Room
  sf::Texture plant_;
  sf::Sprite plant_sprite_;
};

class Arena : public State
{
public:
  void enter(Engine* engine);
  void exit();
  int transition();
private:
};
#endif
