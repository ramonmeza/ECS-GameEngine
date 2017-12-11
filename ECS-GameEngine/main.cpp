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

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(ent);
		window.display();
	}

	return 0;
}