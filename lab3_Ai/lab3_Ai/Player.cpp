#include "Player.h"

void Player::initilize()
{ 
	if (!m_texture.loadFromFile("player.png"))
	{
		std::cout << "error loading texture" << std::endl;
	}
	m_sprite.setPosition(300, 300);
	m_sprite.setScale(1.5, 1.5);
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
	m_sprite.setTexture(m_texture);
}

void Player::update(sf::Time t_deltaTime)
{
    cout << std::to_string(m_velocity.x) << " , " << std::to_string(m_velocity.y) << endl;
   

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_velocity.x -= accel;
        m_sprite.setRotation(-90);
    } 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_velocity.x += accel;
        m_sprite.setRotation(90);
    }
    else {
        m_velocity.x *= decel;
    }
       
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_velocity.y -= accel;
        m_sprite.setRotation(0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_velocity.y += accel;
        m_sprite.setRotation(180);
    }
    else {
        m_velocity.y *= decel;
    }
    if (m_velocity.x < -MAX_SPEED) {
        m_velocity.x = -MAX_SPEED;
    }
    if (m_velocity.x > MAX_SPEED) {
        m_velocity.x = MAX_SPEED;
    }
    if (m_velocity.y < -MAX_SPEED) {
        m_velocity.y = -MAX_SPEED;
    }
    if (m_velocity.y > MAX_SPEED) {
        m_velocity.y = MAX_SPEED;
    }

    m_sprite.move(m_velocity);

  
 
}



sf::Sprite Player::GetSprite()
{
    return m_sprite;
}

void Player::setPostion(sf::Vector2f t_pos)
{
    m_sprite.setPosition(t_pos);
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_sprite);
}
