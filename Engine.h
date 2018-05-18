#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>

class State;
class Player;

class Engine
{
public:
  //Konstruktor
  Engine();
  //Konstruktor-Helper
  void fillRoomVector();
  //Methoden
  void run();
  void handleEvent();
  void drawSpriteVector(std::vector<sf::Sprite> sprite_vector);

  void setSpriteVector(std::vector<sf::Sprite> sprite_vector);
  void appendSpriteVector(std::vector<sf::Sprite> sprite_vector);

  std::vector<sf::Sprite> getSpriteVector() { return sprite_vector_;};
  Player* getPlayer() {return player_;}
private:
  std::vector<sf::Sprite> sprite_vector_;
  std::vector<State*> room_vector_;
  sf::RenderWindow window_;
  bool is_running_;


  //ROOM HANDLING
  void handleRoom();
  int current_room_;
  int next_room_;

  Player* player_;
};



#endif //ENGINE_H
