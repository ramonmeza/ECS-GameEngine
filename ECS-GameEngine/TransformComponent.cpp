#include "TransformComponent.hpp"

TransformComponent::TransformComponent()
{
	// Initialize position, rotationm, and scale
	position = sf::Vector2f(0.0f, 0.0f);
	rotation = 0.0f;
	scale = sf::Vector2f(1.0f, 1.0f);
}

TransformComponent::~TransformComponent()
{
}