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

	/// <summary>
	/// Transform component of the entity.
	/// </summary>
	TransformComponent* transform;

	void Tick(float DeltaTime);
	void AddComponent(Component* component);

	/// <summary>
	/// Returns the first component of a given type.
	/// </summary>
	template<class ComponentType>
	ComponentType* GetComponent()
	{
		// For each component in this entity
		for (auto itr = m_Components.begin(); itr != m_Components.end(); itr++)
		{
			// If the component is of type ComponentType
			ComponentType* comp = dynamic_cast<ComponentType*>(*itr);

			// If the component is of type ComponentType
			if (comp != nullptr)
			{
				// Return the found component
				return comp;
			}
		}

		// No component of type ComponentType found
		return nullptr;
	}

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<Component*> m_Components;
};