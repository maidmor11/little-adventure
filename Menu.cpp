#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Engine.h"
#include <iostream>
#include <vector>

void Menu::enter(Engine* engine)
{
  this->room_sprite_vector_.clear();

  start_button_.loadFromFile("./assets/menu_start_btn.png");
  start_button_sprite_.setTexture(start_button_);
  start_button_sprite_.setPosition(1280/2, 0);

  load_button_.loadFromFile("./assets/menu_load_btn.png");
  load_button_sprite.setTexture(load_button_);
  load_button_sprite_.setPosition(1280/2, 200);

  this->room_sprite_vector_.push_back(start_button_sprite_);
  this->room_sprite_vector_.push_back(load_button_sprite_);

  engine->setSpriteVector(this->room_sprite_vector_);
  std::cout << "Entered Menu" << std::endl;
}

void Menu::exit()
{
  std::cout << "Exit Menu" << std::endl;
}

int Menu::transition(sf::RenderWindow* game_window)
{
  sf::Vector2i mouse_pos = sf::Mouse::getPosition(*game_window);
  if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
  {
    if(start_button_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
      return State::current_room::CREATE_CHARACTER;

    if(load_button_sprite_.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
      return State::current_room::LOAD_SAFE_GAME;
  }
  return State::current_room::MENU;
}
