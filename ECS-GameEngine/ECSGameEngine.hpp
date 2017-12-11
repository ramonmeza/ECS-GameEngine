/// <summary>
/// 
/// </summary>

#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

// Core
#include "World.hpp"
#include "Entity.hpp"
#include "InputManager.hpp"

// Components
#include "Component.hpp"
#include "MovementComponent.hpp"
#include "SpriteComponent.hpp"
#include "TransformComponent.hpp"


class ECSGameEngine
{
public:
	ECSGameEngine();
	~ECSGameEngine();

	void AddEntity(Entity* entity);

	void Run();

	InputManager Input;

private:
	std::vector<Entity*> m_EntityManager;

	void HandleInput();
	void Update();
	void Render();

	sf::RenderWindow* m_Window;
	sf::Clock m_DeltaClock;
};