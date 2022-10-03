#include "fleeAlien.h"

void fleeAlien::setupSprite()
{
	if (!m_texture.loadFromFile("flee.png"))
	{

		std::cout << "problem loading npc" << std::endl;
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(ScreenSize::M_WIDTH / 1.5, ScreenSize::M_HEIGHT / 1.5);
	m_sprite.scale(3.0f, 3.0f);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
}

void fleeAlien::flee(sf::Time& t_deltaTime, Player& t_player)
{
	float m_angleX = t_player.GetSprite().getPosition().x - m_sprite.getPosition().x;
	float m_angleY = t_player.GetSprite().getPosition().y - m_sprite.getPosition().y;

	float rotation = (-atan2(m_angleX, m_angleY)) * 180 / 3.14;
	m_sprite.setRotation(rotation);


	m_velocity = m_sprite.getPosition()-t_player.GetSprite().getPosition();
	float normalise = sqrtf((m_velocity.x * m_velocity.x) + (m_velocity.y * m_velocity.y));
	m_velocity = sf::Vector2f{ (m_velocity.x / normalise) , (m_velocity.y / normalise) };

	if (normalise > 1.5f)
	{
		m_velocity = m_velocity * MAX_SPEED;
	}
	else {
		m_velocity = { 0.0f,0.0f };
	}
	m_sprite.move(m_velocity);
}
void fleeAlien::boundryCheck()
{

	if (m_sprite.getPosition().x > ScreenSize::M_WIDTH)
	{
		m_sprite.setPosition(0 + m_offset, m_sprite.getPosition().y);
	}


	if (m_sprite.getPosition().x < 0 - m_offset)
	{
		m_sprite.setPosition(ScreenSize::M_WIDTH-m_offset, m_sprite.getPosition().y);
	}

	if (m_sprite.getPosition().y < 0 - m_offset)
	{
		m_sprite.setPosition(m_sprite.getPosition().x, ScreenSize::M_HEIGHT- m_offset);
	}


	if (m_sprite.getPosition().y > ScreenSize::M_HEIGHT)
	{
		m_sprite.setPosition(m_sprite.getPosition().x, 0 + m_offset);
	}
}
fleeAlien::fleeAlien()
{
	setupSprite();
}

fleeAlien::~fleeAlien()
{
}

void fleeAlien::update(sf::Time& t_deltaTime, Player& t_player)
{
	flee(t_deltaTime, t_player);
	boundryCheck();
}

void fleeAlien::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_sprite);

}
