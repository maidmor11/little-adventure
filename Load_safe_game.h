#ifndef LOAD_SAVE_GAME_H
#define LOAD_SAVE_GAME_H
#include "Room.h"
class Player;
class Engine;

class Load : public State
{
public:
  void enter(Engine* engine);
  void exit();
  int transition(sf::RenderWindow* game_window);
private:
  std::string read_save_;
  Player* player_;
};


#endif //LOAD_SAVE_GAME_H
