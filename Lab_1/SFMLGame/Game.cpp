#include <Game.h>


using namespace sf;

sf::RenderWindow* window = new RenderWindow(sf::VideoMode(800, 600), "Game");

Game::Game(){}
// calling the individual initiliseing and creating the characters
void Game::initialize()
{
	window->setSize(sf::Vector2u(640, 480));
	thePlayer.initilize();
	theEnemy.initilize();
	
}
// the game loop
void Game::run()
{
	initialize();

	while (window->isOpen())
	{
		update();
		draw();
	}
}
// the update function for the game
void Game::update()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		

	}
	thePlayer.movement();
	theEnemy.movement();

}
// the draw function for the game
void Game::draw()
{
	window->clear();
	thePlayer.render(*window);
	theEnemy.render(*window);
	window->display();
}


