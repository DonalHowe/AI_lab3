#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
class Game
{
	public:
		Game();
		void run();
	private:
		void initialize();
		void update();
		void draw();
		
		Player thePlayer;
		Enemy  theEnemy;

		
};