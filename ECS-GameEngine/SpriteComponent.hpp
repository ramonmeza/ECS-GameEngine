/// <summary>
/// Renders a sprite.
/// </summary>

#pragma once

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Component.hpp"
#include "Entity.hpp"

class SpriteComponent : public Component, public sf::Drawable
{
public:
	explicit SpriteComponent(std::string filePath);
	~SpriteComponent();

	/// <summary>
	/// Tick function will run every frame.
	/// </summary>
	virtual void Tick(float DeltaTime);

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	/// <summary>
	/// The texture needed for the sprite.
	/// </summary>
	sf::Texture* m_Texture;

	/// <summary>
	/// The sprite to be rendered.
	/// </summary>
	sf::Sprite* m_Sprite;
};

