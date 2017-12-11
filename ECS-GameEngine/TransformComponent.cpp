#include "TransformComponent.hpp"

#include "World.hpp"

TransformComponent::TransformComponent(class Entity* parent)
{
	// Set the parent of this component
	m_Parent = parent;

	// Initialize position, rotationm, and scale
	position = sf::Vector2f(0.0f, 0.0f);
	rotation = 0.0f;
	scale = sf::Vector2f(1.0f, 1.0f);
}

TransformComponent::~TransformComponent()
{
}

void TransformComponent::Move(sf::Vector2f dir)
{
	position += dir * TimeDeltaTime;
}

void TransformComponent::Tick(float DeltaTime)
{

}