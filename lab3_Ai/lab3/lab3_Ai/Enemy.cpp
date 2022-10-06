#include "Enemy.h"

Enemy::Enemy()
{

	
}

void Enemy::update(sf::Time& t_deltaTime)
{
		randomNum();
		boundryCheck();
		kinematicWander(t_deltaTime);
		m_WanderLine.clear();
	
		m_text.setPosition(m_sprite.getPosition().x + 55, m_sprite.getPosition().y + 10);
}

void Enemy::render(sf::RenderWindow& t_window)
{
	if (m_alive == true)
	{
		if (m_tracerStatus == true)
		{
			t_window.draw(m_WanderLine);
		}
		t_window.draw(m_sprite);
		t_window.draw(m_text);

		
	}
}

void Enemy::initilise()
{
	setupSprites();
}

void Enemy::randomNum()
{						
	m_randInt = rand() % (10 + 10 + 1) + -10; 
	
}

void Enemy::boundryCheck()
{

	if (m_sprite.getPosition().x > ScreenSize::M_WIDTH)
	{
		m_sprite.setPosition(0 - m_offset, m_sprite.getPosition().y);
	}


	if (m_sprite.getPosition().x < 0 - m_offset)
	{
		m_sprite.setPosition(ScreenSize::M_WIDTH, m_sprite.getPosition().y);
	}

	if (m_sprite.getPosition().y < 0 - m_offset)
	{
		m_sprite.setPosition(m_sprite.getPosition().x, ScreenSize::M_HEIGHT);
	}

	
	if (m_sprite.getPosition().y > ScreenSize::M_HEIGHT)
	{
		m_sprite.setPosition(m_sprite.getPosition().x, 0 - m_offset);
	}
}

void Enemy::setupSprites()
{
	
	
	if (!m_texture.loadFromFile("alien.png"))
	{
	
		std::cout << "problem loading npc" << std::endl;
	}
	
	m_sprite.setTexture(m_texture);
	
	m_sprite.setPosition(50.0f, 50.0f);
	m_sprite.scale(3.0f, 3.0f);
	m_sprite.rotate(m_angle);
	m_sprite.setOrigin(16.0f, 16.0f);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

	radius.setFillColor(sf::Color{ 107, 217, 231, 70 });
	radius.setRadius(radiusF);
	radius.setPosition(m_sprite.getPosition().x - radiusF, m_sprite.getPosition().y - radiusF);

	if (!m_font.loadFromFile("BebasNeue.otf"))
	{
		std::cout << "problem loading font" << std::endl;
	}
	m_text.setFont(m_font);
	m_text.setString("wanderer");
	m_text.setFillColor(sf::Color::Cyan);
	m_text.setCharacterSize(15u);


	
}

void Enemy::kinematicWander(sf::Time& t_deltaTime)
{

	m_angle = m_sprite.getRotation();
	m_angle = m_angle + m_randInt;

	if (m_angle == 360.0)
	{
		m_angle = 0;
	}
	if (m_angle == 0.0)
	{
		m_angle = 359.0;
	}
	RadianAngle = (m_angle - 90) * m_pi / 180;
	m_linePT.x = m_sprite.getPosition().x + radiusF * cos(RadianAngle);
	m_linePT.y = m_sprite.getPosition().y + radiusF * sin(RadianAngle);

	
	m_velocity.x = m_speed * sin(m_angle * t_deltaTime.asMilliseconds() / 1000);
	m_velocity.y = m_speed * -cos(m_angle * t_deltaTime.asMilliseconds() / 1000);
	float squareAns = sqrt((m_velocity.x * m_velocity.x) + (m_velocity.y * m_velocity.y));
	sf::Vector2f normalisedVelocity = m_velocity / squareAns;
	m_sprite.move(m_velocity);
	m_sprite.setRotation(m_angle);
	radius.move(m_velocity);
}