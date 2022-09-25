#include "Enemy.h"

void Enemy::initilize()
{
	if (!m_texture.loadFromFile("zebra.png"))
	{
		cout << "error loading texture" << endl;
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(100, 100);
	m_sprite.setScale(.5, .5);

}

void Enemy::movement()
{
	
	counter++;
	cout << counter << endl;
	if (counter < 1000) {
		m_sprite.move(.15, 0);
	}
	else if (counter > 1000 && counter < 2000)
	{
		m_sprite.move(-.15, 0);
	}
	else if (counter > 2000 && counter < 3000)
	{
		m_sprite.move(0, .15);
	}
	else if (counter > 3000 && counter < 4000)
	{
		m_sprite.move(0, -.15);
	}
	else if (counter > 4000)
	{
		counter = 0;
	}
}

void Enemy::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_sprite);
}
