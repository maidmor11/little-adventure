#ifndef RACE_H
#define RACE_H

class Engine;

class Race
{
public:
  void enter(Engine* engine);
  void exit();
  int transition(sf::RenderWindow* game_window);
private:
  //Objects in Room
  sf::Texture human_banner_;
  sf::Sprite human_banner_sprite_;
};




#endif //RACE_H
