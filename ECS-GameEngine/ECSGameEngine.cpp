#include "ECSGameEngine.hpp"

ECSGameEngine::ECSGameEngine()
{
	// Create a new window
	m_Window = new sf::RenderWindow(sf::VideoMode(880, 800), "ECSGameEngine");
}

ECSGameEngine::~ECSGameEngine()
{
	// Free memory from window
	delete m_Window;

	// Remove dangling pointer
	m_Window = nullptr;

	// Clear the entity manager
	m_EntityManager.clear();
}

/// <summary>
/// Adds an entity to the game.
/// </summary>
void ECSGameEngine::AddEntity(Entity* entity)
{
	if (entity != nullptr)
	{
		m_EntityManager.push_back(entity);
	}
}

/// <summary>
/// Runs the game.
/// </summary>
void ECSGameEngine::Run()
{
	while (m_Window->isOpen())
	{
		HandleInput();
		Update();
		Render();

		// Update delta time
		World::DeltaTime = m_DeltaClock.restart().asSeconds();
		World::TimeSinceWorldBegan = m_DeltaClock.getElapsedTime().asSeconds();
	}
}

/// <summary>
/// Handles window input.
/// </summary>
void ECSGameEngine::HandleInput()
{
	sf::Event event;
	while (m_Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_Window->close();
	}

	/***************************/
	/*                         */
	/* NEED TO FIGURE THIS OUT */
	/*                         */
	/***************************/
	Input.Action("MoveUp");
	Input.Action("MoveDown");
	Input.Action("MoveRight");
	Input.Action("MoveLeft");
}

/// <summary>
/// Updates all of the logic for the game.
/// </summary>
void ECSGameEngine::Update()
{
	// Update each entity
	for(auto itr = m_EntityManager.begin(); itr != m_EntityManager.end(); itr++)
	{
		(*itr)->Tick(World::DeltaTime);
	}

	std::cout << "DeltaTime: " << World::DeltaTime << std::endl;
}

/// <summary>
/// Renders all renderable components in the game.
/// </summary>
void ECSGameEngine::Render()
{
	m_Window->clear();

	// Render each entity
	for (auto itr = m_EntityManager.begin(); itr != m_EntityManager.end(); itr++)
	{
		m_Window->draw(*(*itr));
	}

	m_Window->display();
}