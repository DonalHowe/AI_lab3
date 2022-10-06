#include "pursue.h"

void pursue::setupdSprite()
{

	if (!m_texture.loadFromFile("seek.png"))
	{

		std::cout << "problem loading npc" << std::endl;
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(ScreenSize::M_WIDTH / 2, ScreenSize::M_HEIGHT / 2);
	m_sprite.scale(3.0f, 3.0f);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);

	m_sprite.setColor(sf::Color::Red);
	if (!m_font.loadFromFile("BebasNeue.otf"))
	{
		std::cout << "problem loading font" << std::endl;
	}
	m_text.setFont(m_font);
	m_text.setString("PURSUE");
	m_text.setFillColor(sf::Color::Magenta);
	m_text.setCharacterSize(15u);
}


void pursue::pursueFunc(Player& t_player)
{
	
	float angleX = m_sprite.getPosition().x - t_player.GetSprite().getPosition().x;
	float angleY = m_sprite.getPosition().y - t_player.GetSprite().getPosition().y;

	float rotation = ((-atan2(angleX, angleY) * 180) / 3.14);
	m_sprite.setRotation(rotation);


	m_velocity = t_player.GetheadingPoint() - m_sprite.getPosition();
	float squareRootVelocity = sqrtf(m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y);
	m_velocity = sf::Vector2f{ m_velocity.x / squareRootVelocity , m_velocity.y / squareRootVelocity };
	m_velocity = m_velocity * maxSpeed;
	
	m_sprite.move(m_velocity);
}

pursue::pursue()
{
	setupdSprite();
}

pursue::~pursue()
{
}

void pursue::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_sprite);
	t_window.draw(m_text);
}

void pursue::update(sf::Time& t_deltatime, Player& t_player)
{
	pursueFunc(t_player);
	m_text.setPosition(m_sprite.getPosition().x-40, m_sprite.getPosition().y-15);
}
