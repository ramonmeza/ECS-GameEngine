#include "World.hpp"

float World::DeltaTime = 0.0f;
float World::TimeSinceWorldBegan = 0.0f;

sf::Vector2f World::up = sf::Vector2f(0.0f, -1.0f);
sf::Vector2f World::down = sf::Vector2f(0.0f, 1.0f);
sf::Vector2f World::right = sf::Vector2f(1.0f, 0.0f);
sf::Vector2f World::left = sf::Vector2f(-1.0f, 0.0f);