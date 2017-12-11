/// <summary>
/// Base class for all components.
/// </summary>

#pragma once

class Entity;

class Component
{
public:
	Component() 
	{
		// Initialize the parent pointer to nullptr
		m_Parent = nullptr;
	}

	virtual ~Component() 
	{ 
		// Remove dangling pointer
		m_Parent = nullptr; 
	}

	/// <summary>
	/// Sets the parent of this component to the given entity.
	/// </summary>
	virtual void SetParent(Entity* parent)
	{
		// Set the parrent
		m_Parent = parent;
	}

	/// <summary>
	/// Tick function must be defined in derived class.
	/// </summary>
	virtual void Tick(float DeltaTime) = 0;

protected:
	/// <summary>
	/// Parent entity to this component.
	/// </summary>
	Entity* m_Parent;
};

