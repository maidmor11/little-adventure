#ifndef PLAYER_H
#define PLAYER_H
#include <fstream>
#include <SFML/Graphics.hpp>

class Player
{
public:
  Player();
  Player(std::string player_file);
private:
  sf::Texture player_texture_;
  sf::Sprite player_sprite_;

};
#endif
