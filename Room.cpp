#include "Room.h"
#include <iostream>

void Menu::enter()
{
  std::cout << "Entered Menu" << std::endl;
}

void Menu::exit()
{
  std::cout << "Exit Menu" << std::endl;
}

int Menu::transition()
{
  int x;
  std::cin >> x;
  switch(x)
  {
    case MENU:
      return current_room::MENU;
    case ARENA:
      return current_room::ARENA;
    default:
      return current_room::MENU;
  }
}


void Arena::enter()
{
  std::cout << "Entered Arena" << std::endl;
}

void Arena::exit()
{
  std::cout << "Exit Arena" << std::endl;
}

int Arena::transition()
{
  int x;
  std::cin >> x;
  switch(x)
  {
    case MENU:
      return current_room::MENU;
    case ARENA:
      return current_room::ARENA;
    default:
      return current_room::MENU;
  }
}
