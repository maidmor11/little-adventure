#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

#include "Load_safe_game.h"

void Load::enter(Engine* engine)
{
  std::cout << "Entered LOAD_SAFE_GAME" << std::endl;

}

void Load::exit()
{
  std::cout << "Exit Load Savegames" << std::endl;
}

int Load::transition(sf::RenderWindow* game_window)
{
  return State::current_room::ARENA;
}
