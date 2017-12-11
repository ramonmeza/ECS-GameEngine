#include "MovementComponent.hpp"

#include "Entity.hpp"
#include "World.hpp"

MovementComponent::MovementComponent()
{
}

MovementComponent::~MovementComponent()
{
}

/// <summary>
/// Moves entity in a given direction
/// </summary>
void MovementComponent::Move(sf::Vector2f direction)
{
	// If the parent isn't nullptr
	if (m_Parent != nullptr)
	{
		// Move the entity in the given direction at the given speed
		m_Parent->transform->position += direction * m_Speed * World::DeltaTime;
	}
}

void MovementComponent::MoveUp() { Move(World::up); }
void MovementComponent::MoveDown() { Move(World::down); }
void MovementComponent::MoveRight() { Move(World::right); }
void MovementComponent::MoveLeft() { Move(World::left); }