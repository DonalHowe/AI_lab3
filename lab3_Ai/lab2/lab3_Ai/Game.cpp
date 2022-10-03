

#include "Game.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ ScreenSize::M_WIDTH, ScreenSize::M_HEIGHT, 32U }, "Ai Labs" },m_exitGame{false}//ue game will exit

{

	player.initilize();
	enemy.initilise();
	
	
}


Game::~Game()
{
}



void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}



void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}


void Game::update(sf::Time t_deltaTime)
{
	enemy.update(t_deltaTime);
	player.update(t_deltaTime);
	arriveNpc.update(t_deltaTime,player);
	fleeNpc.update(t_deltaTime, player);
	seekNpc.update(t_deltaTime,player);
	if (m_exitGame)
	{
		m_window.close();
	}
}


void Game::render()
{
	m_window.clear(sf::Color::Black);

	player.render(m_window);
	enemy.render(m_window);
	seekNpc.render(m_window);
	arriveNpc.render(m_window);
	fleeNpc.render(m_window);
	
	m_window.display();
}



