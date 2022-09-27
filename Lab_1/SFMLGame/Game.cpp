#include <Game.h>

static double const MS_PER_UPDATE = 10.0;
static double const m_width = 800.0f;
static double const m_height = 800.0f;


Game::Game() : m_window(sf::VideoMode(m_width, m_height, 32), "AI LAB", sf::Style::Default)
{
	thePlayer.initilize();
	theEnemy.initilize();
}

void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(lag);
			lag -= MS_PER_UPDATE;
		}
		update(lag);

		render();
	}
}
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(event);
	}
}

void Game::boundryCheck()
{
	if (thePlayer.GetSprite().getPosition().x > m_width)
	{
		thePlayer.setPostion(sf::Vector2f{ 10,thePlayer.GetSprite().getPosition().y });
	}
	else if (thePlayer.GetSprite().getPosition().x < 0)
	{
		thePlayer.setPostion(sf::Vector2f{ m_width-5,thePlayer.GetSprite().getPosition().y });
	}
	if (thePlayer.GetSprite().getPosition().x > m_height)
	{
		thePlayer.setPostion(sf::Vector2f{ thePlayer.GetSprite().getPosition().x ,5 });
	}
	else if (thePlayer.GetSprite().getPosition().x < 0)
	{
		thePlayer.setPostion(sf::Vector2f{ thePlayer.GetSprite().getPosition().x ,m_height-5 });
	}
}


void Game::processGameEvents(sf::Event& t_event)
{
	// check if the event is a a mouse button release
	if (sf::Event::KeyPressed == t_event.type)
	{
		switch (t_event.key.code)
		{
		case sf::Keyboard::Escape:
			m_window.close();

			break;
		case sf::Keyboard::Space:
			break;
		default:
			break;
		}
	}
}
// the update function for the game
void Game::update(double dt)
{
	thePlayer.update(dt);
	theEnemy.update(dt);
	//boundryCheck();
}

// the draw function for the game
void Game::render()
{
	m_window.clear();
	thePlayer.render(m_window);
	theEnemy.render(m_window);
	m_window.display();
}


