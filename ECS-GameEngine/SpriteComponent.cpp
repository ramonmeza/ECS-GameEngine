#include <iostream>

#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(std::string filePath, Entity* parent)
{
	// Set the parent of this component
	m_Parent = parent;

	try
	{
		// Create a new sprite
		m_Texture = new sf::Texture();

		// Try to load texture from the given filepath
		if (!m_Texture->loadFromFile(filePath))
			throw "Failed to load texture: " + filePath;

		// Create sprite from the texture
		m_Sprite = new sf::Sprite(*m_Texture);

		// Position the sprite to the parent's transform
		m_Sprite->setPosition(m_Parent->transform->position);
		m_Sprite->setRotation(m_Parent->transform->rotation);
		m_Sprite->setScale(m_Parent->transform->scale);
	}
	catch (std::string ExceptionMsg)
	{
		// Catch exception and print out the error message
		std::cerr << ExceptionMsg << std::endl;
	}
}

SpriteComponent::~SpriteComponent()
{
	// Free memory from texture
	if (m_Texture != nullptr)
	{
		delete m_Texture;
		m_Texture = nullptr;
	}

	// Free memory from sprite
	if (m_Sprite != nullptr)
	{
		delete m_Sprite;
		m_Sprite = nullptr;
	}
}

/// <summary>
/// The tick function moves the sprite to match the parent's transform.
/// </summary>
void SpriteComponent::Tick(float DeltaTime)
{
	// Position the sprite to the parent's transform
	m_Sprite->setPosition(m_Parent->transform->position);
	m_Sprite->setRotation(m_Parent->transform->rotation);
	m_Sprite->setScale(m_Parent->transform->scale);
}

/// <summary>
/// Overload the draw function from sf::Drawable to draw the sprite.
/// </summary>
void SpriteComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_Texture != nullptr && m_Sprite != nullptr)
	{
		// Draw the sprite
		target.draw(*m_Sprite);
	}
}