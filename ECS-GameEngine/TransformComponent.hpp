/// <summary>
/// 
/// </summary>

#pragma once

#include <SFML/System/Vector2.hpp>

#include "Component.hpp"

class TransformComponent : public Component
{
public:
	TransformComponent();
	~TransformComponent();

	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;

	void Move(sf::Vector2f dir);

	virtual void Tick(float DeltaTime) {}
};