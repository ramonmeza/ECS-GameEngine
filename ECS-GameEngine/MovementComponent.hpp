/// <summary>
/// Allows basic movement for entities
/// </summary>

#pragma once

#include <SFML/System/Vector2.hpp>

#include "Component.hpp"

class MovementComponent : public Component
{
public:
	MovementComponent();
	~MovementComponent();

	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();

	void SetSpeed(float speed) { m_Speed = speed; }
	float GetSpeed() { return m_Speed; }

	virtual void Tick(float DeltaTime) {}

protected:
	float m_Speed;

private:
	void Move(sf::Vector2f direction);
};

