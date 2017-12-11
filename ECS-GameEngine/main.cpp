#include <iostream>

#include <SFML/Graphics.hpp>

#include "SpriteComponent.hpp"

using namespace sf;
using namespace std;

int main(int argc, char* argv[])
{
	RenderWindow window(VideoMode(600,600), "ECS-GameEngine");

	Entity ent;
	ent.AddComponent(new SpriteComponent("assets/sprites/sprite.png", &ent));

	sf::Clock deltaClock;
	sf::Time deltaTime = deltaClock.restart();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		ent.Tick(deltaTime.asSeconds());
		ent.transform->position += sf::Vector2f(10.0f, 10.0f) * deltaTime.asSeconds();

		window.clear();
		window.draw(ent);
		window.display();

		deltaTime = deltaClock.restart();
	}

	return 0;
}