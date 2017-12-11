/// <summary>
/// 
/// </summary>

#pragma once

#include <SFML/System/Vector2.hpp>

#include "Component.hpp"

class TransformComponent : public Component
{
public:
	explicit TransformComponent(class Entity* parent);
	~TransformComponent();

	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;
};

