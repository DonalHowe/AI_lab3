#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

class Game
{
	public:
	Game();
	void run();		
	sf::RenderWindow m_window;	
	void update(double dt);
	void render();
	void processGameEvents(sf::Event& t_event);
	void processEvents();
	private:
		void boundryCheck();
	
		
		Player thePlayer;
		Enemy  theEnemy;

		
};