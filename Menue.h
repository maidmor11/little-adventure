#ifndef MENUE_H
#define MENUE_H

class Engine;

class Menu : public State
{
public:
  void enter(Engine* engine);
  void exit();
  int transition(sf::RenderWindow* game_window);
private:
  //Objects in Room
  sf::Texture plant_;
  sf::Sprite plant_sprite_;
};


#endif //MENUE_H
