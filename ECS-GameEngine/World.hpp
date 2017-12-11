/// <summary>
/// Defines world functions and variable useful for all classes.
/// </summary>

#pragma once

#include <SFML/System/Vector2.hpp>

class World
{
public:
	World() {};
	~World() {};

	/// <summary>
	/// Time since the last frame (in seconds).
	/// </summary>
	static float DeltaTime;

	/// <summary>
	/// Time since the world was created (in seconds).
	/// </summary>
	static float TimeSinceWorldBegan;

	/// <summary>
	/// Absolute up vector.
	/// </summary>
	static sf::Vector2f up;

	/// <summary>
	/// Absolute down vector.
	/// </summary>
	static sf::Vector2f down;

	/// <summary>
	/// Absolute right vector.
	/// </summary>
	static sf::Vector2f right;

	/// <summary>
	/// Absolute left vector.
	/// </summary>
	static sf::Vector2f left;
};