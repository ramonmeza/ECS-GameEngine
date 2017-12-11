#include <iostream>

#include <SFML/Graphics.hpp>

#include "InputManager.hpp"
#include "SpriteComponent.hpp"

#include "World.hpp"
float TimeDeltaTime = 0.0f;

using namespace sf;
using namespace std;

int main(int argc, char* argv[])
{
	// Create window
	RenderWindow window(VideoMode(600,600), "ECS-GameEngine");

	// Create entities
	Entity ent;
	ent.AddComponent(new SpriteComponent("assets/sprites/sprite.png", &ent));

	// Setup inputs
	InputManager Input;
	Input.MapKey("MoveUp", sf::Keyboard::Key::Up, &ent, [&]() { ent.transform->Move(sf::Vector2f(0.0f, -100.0f)); });
	Input.MapKey("MoveDown", sf::Keyboard::Key::Down, &ent, [&]() { ent.transform->Move(sf::Vector2f(0.0f, 100.0f)); });
	Input.MapKey("MoveRight", sf::Keyboard::Key::Right, &ent, [&]() { ent.transform->Move(sf::Vector2f(100.0f, 0.0f)); });
	Input.MapKey("MoveLeft", sf::Keyboard::Key::Left, &ent, [&]() { ent.transform->Move(sf::Vector2f(-100.0f, 0.0f)); });

	// Delta time
	sf::Clock deltaClock;
	sf::Time dt = deltaClock.restart();

	// Game loop
	while (window.isOpen())
	{
		// Input handling
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		// Test action mappings
		//std::function<void()> f = std::function<void()>([&]() {ent.transform->position.y += 10.0f * deltaTime.asSeconds(); });

		if (Input.Key("MoveUp"))
			Input.Action("MoveUp");

		if (Input.Key("MoveDown"))
			Input.Action("MoveDown");

		if (Input.Key("MoveRight"))
			Input.Action("MoveRight");

		if (Input.Key("MoveLeft"))
			Input.Action("MoveLeft");


		// Update
		ent.Tick(TimeDeltaTime);
		//ent.transform->position += sf::Vector2f(10.0f, 10.0f) * deltaTime.asSeconds();

		// Render
		window.clear();
		window.draw(ent);
		window.display();

		// Delta time
		dt = deltaClock.restart();
		TimeDeltaTime = dt.asSeconds();
	}

	return 0;
}