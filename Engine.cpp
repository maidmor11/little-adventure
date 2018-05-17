#include <SFML/Graphics.hpp>
#include <vector>
#include "Engine.h"

Engine::Engine()
{

  window_.create(sf::VideoMode(600,400), "Adventure");
  // window_.setVerticalSyncEnabled(false);
  sprite_vector_.clear();
}

void Engine::run()
{
  is_running_ = true;
  while(is_running_ == true && window_.isOpen())
  {
    window_.clear();
    sf::Event e;
    while(window_.pollEvent(e))
    {
      window_.close();
    }
    drawSpriteVector(sprite_vector_);
    window_.display();
  }
}

void Engine::drawSpriteVector(std::vector<sf::Sprite> sprite_vector)
{
  for(auto &sprite : sprite_vector)
  {
    window_.draw(sprite);
  }
}

void Engine::setSpriteVector(std::vector<sf::Sprite> sprite_vector)
{
  sprite_vector_ = sprite_vector;
}
