#ifndef LOAD_SAVE_GAME_H
#define LOAD_SAVE_GAME_H

class Player;

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
