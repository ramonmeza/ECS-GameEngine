#include "Entity.hpp"

Entity::Entity()
{
	// Create the transform component
	transform = new TransformComponent(this);
}

Entity::~Entity()
{
	// Free the transform component
	delete transform;
	transform = nullptr;

	// Clear the components list
	m_Components.clear();
}

/// <summary>
/// Adds a given component to the entity.
/// </summary>
void Entity::AddComponent(class Component* component)
{
	if (component != nullptr)
	{
		// Add the component to the components list
		m_Components.push_back(component);
	}
}

void Entity::Tick(float DeltaTime)
{
	// For each component in this entity
	for (auto itr = m_Components.begin(); itr != m_Components.end(); itr++)
	{
		// Update each component
		(*itr)->Tick(DeltaTime);
	}
}

/// <summary>
/// Overload the draw function from sf::Drawable to draw each drawable component.
/// </summary>
void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// For each component in this entity
	for (auto itr = m_Components.begin(); itr != m_Components.end(); itr++)
	{
		// If the component inherits from sf::Drawable class
		sf::Drawable* comp = dynamic_cast<sf::Drawable*>(*itr);
		if (comp != nullptr)
		{
			// Draw the component
			target.draw(*comp, states);
		}
	}
}