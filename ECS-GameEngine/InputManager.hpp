/// <summary>
/// 
/// </summary>

#pragma once

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

#include <SFML/Window/Keyboard.hpp>

class Entity;

class InputManager
{
public:
	InputManager();
	~InputManager();

	void MapKey(std::string name, sf::Keyboard::Key key, std::function<void()> action);
	bool Key(std::string name);

	void Action(std::string name);

private:
	struct KeyAction
	{
		std::string ActionName;
		sf::Keyboard::Key ActionKey;
		
		std::function<void()> Action;

		KeyAction(std::string name, sf::Keyboard::Key key, std::function<void()> action)
		{
			ActionName = name;
			ActionKey = key;
			Action = action;
		}
	};

	std::vector<KeyAction*> m_KeyMappings;
};