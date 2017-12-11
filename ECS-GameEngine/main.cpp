#include "ECSGameEngine.hpp"

int main(int argc, char* argv[])
{
	// Create a game engine
	ECSGameEngine game;

	// Create entity
	Entity* ent = new Entity();
	ent->AddComponent(new SpriteComponent("assets/sprites/sprite.png"));

	// Setup entity input
	game.Input.MapKey("MoveUp", sf::Keyboard::Key::Up, [&]() { ent->transform->Move(sf::Vector2f(0.0f, -100.0f)); });
	game.Input.MapKey("MoveDown", sf::Keyboard::Key::Down, [&]() { ent->transform->Move(sf::Vector2f(0.0f, 100.0f)); });
	game.Input.MapKey("MoveRight", sf::Keyboard::Key::Right, [&]() { ent->transform->Move(sf::Vector2f(100.0f, 0.0f)); });
	game.Input.MapKey("MoveLeft", sf::Keyboard::Key::Left, [&]() { ent->transform->Move(sf::Vector2f(-100.0f, 0.0f)); });

	// Add entity to game
	game.AddEntity(ent);

	// Run the game
	game.Run();

	return 0;
}