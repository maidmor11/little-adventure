#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>
class Engine
{
public:
  //Konstruktor
  Engine();

  //Methoden
  void run();
  void handleEvent();
  void drawSpriteVector(std::vector<sf::Sprite> sprite_vector);

  void setSpriteVector(std::vector<sf::Sprite> sprite_vector);
  std::vector<sf::Sprite> getSpriteVector() { return sprite_vector_;};
private:
  std::vector<sf::Sprite> sprite_vector_;
  sf::RenderWindow window_;
  bool is_running_;
};



#endif //ENGINE_H
