#include "InputManager.hpp"

InputManager::InputManager()
{

}

InputManager::~InputManager()
{
	// Clear key mappings
	m_KeyMappings.clear();
}

void InputManager::MapKey(std::string name, sf::Keyboard::Key key, Entity* object, std::function<void()> action)
{
	// Create a new key action to add to the mappings
	KeyAction* mapping = new KeyAction(name, key, action);

	// Add the new key action to the key mappings
	m_KeyMappings.push_back(mapping);
}

bool InputManager::Action(std::string name)
{
	// Try to find action mapping
	auto found = std::find_if(m_KeyMappings.begin(), m_KeyMappings.end(), 
					[name](const KeyAction* obj) { return obj->ActionName == name; });

	// If the key mapping exists
	if (found != m_KeyMappings.end())
	{
		// Return whether the action key is pressed
		return sf::Keyboard::isKeyPressed((*found)->ActionKey);
	}

	// Key mapping was not found
	return false;
}

void InputManager::ActionTest(std::string name)
{
	// Try to find action mapping
	auto found = std::find_if(m_KeyMappings.begin(), m_KeyMappings.end(),
		[name](const KeyAction* obj) { return obj->ActionName == name; });

	// If the key mapping exists
	if (found != m_KeyMappings.end())
	{
		// If the action key is pressed
		if (sf::Keyboard::isKeyPressed((*found)->ActionKey))
		{
			// Return the corresponding action
			return (*found)->Action();
		}
	}

	// Key mapping was not found
	return;
}