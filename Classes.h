#ifndef CLASSES_H
#define CLASSES_H
#include "Room.h"

class Engine;
class Classes : public State
{
public:
  void enter(Engine* engine);
  void exit();
  int transition(sf::RenderWindow* game_window);
private:
  //Wizard banner
  sf::Texture wizard_banner_;
  sf::Sprite wizard_banner_sprite_;
};

#endif
