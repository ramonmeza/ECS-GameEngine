#include "ECSGameEngine.hpp"

int main(int argc, char* argv[])
{
	// Create a game engine
	ECSGameEngine game;

	// Create entity
	Entity* ent = new Entity();

	// Add sprite component
	ent->AddComponent(new SpriteComponent("assets/sprites/sprite.png"));

	// Add movement component
	ent->AddComponent(new MovementComponent());
	ent->GetComponent<MovementComponent>()->SetSpeed(500.0f);

	// Setup entity input
	game.Input.MapKey("MoveUp", sf::Keyboard::Key::W, [&]() { ent->GetComponent<MovementComponent>()->MoveUp(); });
	game.Input.MapKey("MoveDown", sf::Keyboard::Key::A, [&]() { ent->GetComponent<MovementComponent>()->MoveDown(); });
	game.Input.MapKey("MoveRight", sf::Keyboard::Key::S, [&]() { ent->GetComponent<MovementComponent>()->MoveRight(); });
	game.Input.MapKey("MoveLeft", sf::Keyboard::Key::D, [&]() { ent->GetComponent<MovementComponent>()->MoveLeft(); });

	// Add entity to game
	game.AddEntity(ent);

	// Run the game
	game.Run();

	return 0;
}