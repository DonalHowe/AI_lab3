

#include "Game.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ ScreenSize::M_WIDTH, ScreenSize::M_HEIGHT, 32U }, "Ai Labs" },m_exitGame{false}//ue game will exit

{

	player.initilize();
	enemy.initilise();
	
	arriveNpc[0].m_sprite.setPosition(600, 500);
	arriveNpc[1].m_sprite.setPosition(50, 500);
	arriveNpc[1].m_sprite.setColor(sf::Color::Cyan);
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
	
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		seekNpc.update(t_deltaTime, player);
   }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {

		enemy.update(t_deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
		arriveNpc[0].update(t_deltaTime, player);
		arriveNpc[1].update(t_deltaTime, player);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
		purseueNpc.update(t_deltaTime, player);
	}
		
	
	
		


	

	
	player.update(t_deltaTime);
	
	
	
	if (m_exitGame)
	{
		m_window.close();
	}
}


void Game::render()
{
	m_window.clear(sf::Color::Black);

	
		seekNpc.render(m_window);

	
		arriveNpc[0].render(m_window);
		arriveNpc[1].render(m_window);
		purseueNpc.render(m_window);
	
		enemy.render(m_window);

	player.render(m_window);
	
	
	
	
	
	m_window.display();
}



