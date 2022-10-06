
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "ScreenSize.h"
#include "seekAlien.h"
#include "arriveAlien.h"
#include "pursue.h"

class Game
{
public:
	Game();
	~Game();

	void run();
	Enemy enemy;
	Player player;
	seekAlien seekNpc;
	arriveAlien arriveNpc[2];
	pursue purseueNpc;
	
private:
	sf::Font gameFont;
	sf::Text gameText;
	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	

	sf::RenderWindow m_window; // main SFML window
	
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

