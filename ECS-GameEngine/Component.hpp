/// <summary>
/// Base class for all components.
/// </summary>

#pragma once

class Entity;

class Component
{
public:
	Component() {};
	virtual ~Component() 
	{ 
		// Remove dangling pointer
		m_Parent = nullptr; 
	};

	virtual void Tick(float DeltaTime) = 0;

protected:
	Entity* m_Parent;
};

