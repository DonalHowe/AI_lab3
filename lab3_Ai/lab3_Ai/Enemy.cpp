#include "Enemy.h"

sf::Sprite Enemy::GetSprite()
{
	return m_sprite;
}

void Enemy::initilize()
{
	srand(time(nullptr));
	if (!m_texture.loadFromFile("alien.png"))
	{
		cout << "error loading texture" << endl;
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(100, 100);
	m_sprite.setScale(1.5, 1.5);
	choice= rand() % 3;

}

void Enemy::update(sf::Time t_deltaTime  )
{
	
	counter++;
	
	if (counter < 1000) {
		m_sprite.move(.15, 0);
	}
	else if (choice==1)
	{
		m_sprite.move(-.15, 0);
	}
	else if (choice==2)
	{
		m_sprite.move(0, .15);
	}
	else if (choice==3)
	{
		m_sprite.move(0, -.15);
	}
	
	
}

void Enemy::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_sprite);
}
