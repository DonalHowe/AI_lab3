#include "arriveAlien.h"

void arriveAlien::setupSprite()
{
	if (!m_texture.loadFromFile("arrive.png"))
	{

		std::cout << "problem loading npc" << std::endl;
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(ScreenSize::M_WIDTH / 1.5, ScreenSize::M_HEIGHT / 1.5);
	m_sprite.scale(3.0f, 3.0f);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);

	if (!m_font.loadFromFile("BebasNeue.otf"))
	{
		std::cout << "problem loading font" << std::endl;
	}
	m_text.setFont(m_font);
	m_text.setString("arrive");
	m_text.setFillColor(sf::Color::Red);
	m_text.setCharacterSize(15u);

	m_leftLine[1].color = sf::Color::Red;
	m_leftLine[2].color = sf::Color::Red;
	m_rightLine[2].color = sf::Color::Red;
	m_leftLine[2].color = sf::Color::Red;



}

void arriveAlien::arrive(sf::Time& t_deltaTime, Player& t_player)
{

	m_rightLine[1].position= m_sprite.getPosition();
	
	m_leftLine[1].position= m_sprite.getPosition();

	m_velocity =  t_player.GetSprite().getPosition()- m_sprite.getPosition();
	float m_angleX = t_player.GetSprite().getPosition().x - m_sprite.getPosition().x;
	float m_angleY = t_player.GetSprite().getPosition().y - m_sprite.getPosition().y;

	float rotation = (-atan2(m_angleX, m_angleY)) * 180 / 3.14;

	distancefromPt = sqrtf((m_velocity.x * m_velocity.x) + (m_velocity.y * m_velocity.y));
	 
	if (distancefromPt < t_player.GetSprite().getGlobalBounds().width)
	{
		m_velocity = { 0.0f,0.0f };	
	}
	else {
		m_velocity / timeToTarget;
		if (distancefromPt > MAX_SPEED) {
			float normalise = sqrtf((m_velocity.x * m_velocity.x) + (m_velocity.y * m_velocity.y));
			m_velocity = sf::Vector2f{ (m_velocity.x / normalise) , (m_velocity.y / normalise) };
			m_velocity = m_velocity * MAX_SPEED;
		}
	}
	m_sprite.move(m_velocity);
	m_sprite.setRotation(rotation);
	leftlinePtX= 20 * sin(rotation);
	leftlinePtY= 20 * -cos(rotation);

	rightlinePtX = 20 * sin(rotation);
	rightlinePtY = 20 * -cos(rotation);

	m_rightLine[2].position.x = rightlinePtX;
	m_rightLine[2].position.y = rightlinePtX;

}

arriveAlien::arriveAlien()
{
	setupSprite();
}

arriveAlien::~arriveAlien()
{
}

void arriveAlien::update(sf::Time& t_deltaTime,Player & t_player)
{
	arrive(t_deltaTime, t_player);
	m_text.setPosition(m_sprite.getPosition().x+55, m_sprite.getPosition().y+10);
}

void arriveAlien::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
	t_window.draw(m_sprite);
	t_window.draw(m_leftLine,2,sf::Lines);
	
}
