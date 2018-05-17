#include <SFM/Graphics.hpp>
#include "Menue.h"
#include "Engine.h"

void Menu::enter(Engine* engine)
{
  this->room_sprite_vector_.clear();
  plant_.loadFromFile("./plant01.png");
  plant_sprite_.setTexture(plant_);
  this->room_sprite_vector_.push_back(plant_sprite_);
  engine->setSpriteVector(this->room_sprite_vector_);
  std::cout << "Entered Menu" << std::endl;
}

void Menu::exit()
{
  std::cout << "Exit Menu" << std::endl;
}

int Menu::transition(sf::RenderWindow* game_window)
{

}
