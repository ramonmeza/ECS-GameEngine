/// <summary>
/// Entities are the basic object for the game engine. They re nade up of components.
/// </summary>

#pragma once

#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Component.hpp"
#include "TransformComponent.hpp"

class Entity : public sf::Drawable
{
public:
	Entity();
	~Entity();

	void Tick(float DeltaTime);
	void AddComponent(Component* component);

	class TransformComponent* transform;

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<Component*> m_Components;
};