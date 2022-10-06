#include "seekAlien.h"

void seekAlien::update(sf::Time& t_deltatime,Player & t_player)
{
	seek(t_deltatime, t_player);
	m_text.setPosition(m_sprite.getPosition().x + 55, m_sprite.getPosition().y + 10);
}

void seekAlien::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_sprite);
	t_window.draw(m_text);
}

seekAlien::seekAlien()
{
	setupAlien();
}

void seekAlien::setupAlien()
{

	if (!m_texture.loadFromFile("seek.png"))
	{

		std::cout << "problem loading npc" << std::endl;
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(ScreenSize::M_WIDTH/2, ScreenSize::M_HEIGHT/2);
	m_sprite.scale(3.0f, 3.0f);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);


	m_radius.setRadius(radiusCircle);
	m_radius.setFillColor(sf::Color::Red);
	if (!m_font.loadFromFile("BebasNeue.otf"))
	{
		std::cout << "problem loading font" << std::endl;
	}
	m_text.setFont(m_font);
	m_text.setString("SEEK");
	m_text.setFillColor(sf::Color::Green);
	m_text.setCharacterSize(15u);
}

void seekAlien::seek(sf::Time& t_deltaTime, Player& t_player)
{
	float m_angleX = t_player.GetSprite().getPosition().x - m_sprite.getPosition().x;
	float m_angleY = t_player.GetSprite().getPosition().y- m_sprite.getPosition().y;

	float rotation = (-atan2(m_angleX, m_angleY)) * 180 / 3.14;
	m_sprite.setRotation(rotation);

	
	m_velocity = t_player.GetSprite().getPosition() - m_sprite.getPosition();
	float normalise = sqrtf((m_velocity.x * m_velocity.x) + (m_velocity.y * m_velocity.y));
	m_velocity = sf::Vector2f{( m_velocity.x / normalise) , (m_velocity.y / normalise) };
	
	if (normalise >1.5f)
	{
		m_velocity = m_velocity * maxSpeed;
	}
	else {
		m_velocity={ 0.0f,0.0f };
	}
	m_sprite.move(m_velocity);
	
}



seekAlien::~seekAlien()
{
}
