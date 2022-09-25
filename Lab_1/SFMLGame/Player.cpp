#include "Player.h"

void Player::initilize()
{ 
	if (!m_texture.loadFromFile("sloth.png"))
	{
		std::cout << "error loading texture" << std::endl;
	}
	m_sprite.setPosition(300, 300);
	m_sprite.setScale(.5, .5);
	m_sprite.setTexture(m_texture);
}

void Player::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_sprite.move(-5, 0);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_sprite.move(5, 0);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_sprite.move(0, -5);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_sprite.move(0,5);

	}
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_sprite);
}
