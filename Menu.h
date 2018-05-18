#ifndef MENUE_H
#define MENUE_H

#include "Room.h"
class Engine;

class Menu : public State
{
public:
  void enter(Engine* engine);
  void exit();
  int transition(sf::RenderWindow* game_window);
private:
  //Objects in Room
  sf::Texture start_button_;
  sf::Sprite start_button_sprite_;

  sf::Texture load_button_;
  sf::Sprite load_button_sprite_;
};


#endif //MENUE_H
