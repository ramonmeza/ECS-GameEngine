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
	explicit SpriteComponent(std::string filePath, Entity* parent);
	~SpriteComponent();

	virtual void Tick(float DeltaTime);

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Texture* m_Texture;
	sf::Sprite* m_Sprite;
};

