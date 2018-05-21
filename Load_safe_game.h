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
  int loadSaveGame(int save_nr);
private:
  std::string read_save_;
  Player* player_;

  sf::Texture save_nr_1_;
  sf::Sprite save_nr_1_sprite_;

  sf::Texture save_nr_2_;
  sf::Sprite save_nr_2_sprite_;

  sf::Texture save_nr_3_;
  sf::Sprite save_nr_3_sprite_;

  sf::Texture save_nr_4_;
  sf::Sprite save_nr_4_sprite_;

  sf::Texture save_nr_5_;
  sf::Sprite save_nr_5_sprite_;
};


#endif //LOAD_SAVE_GAME_H
