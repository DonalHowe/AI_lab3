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

void Player::update(double dt)
{
    cout<< std::to_string(m_velocity.x) << " , ";
    cout<< std::to_string(m_velocity.y) << std::endl;
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


    m_postiion += m_velocity;
    m_sprite.setPosition(m_postiion);
    if (m_sprite.getPosition().x > 600)
    {
        m_sprite.setPosition(sf::Vector2f{ 50,m_sprite.getPosition().y });
    }
    else if (m_sprite.getPosition().x < 0)
    {
    	m_sprite.setPosition(sf::Vector2f{ 600-5,m_sprite.getPosition().y });
    }
    //if (thePlayer.GetSprite().getPosition().x > m_height)
    //{
    //	thePlayer.setPostion(sf::Vector2f{ thePlayer.GetSprite().getPosition().x ,5 });
    //}
    //else if (thePlayer.GetSprite().getPosition().x < 0)
    //{
    //	thePlayer.setPostion(sf::Vector2f{ thePlayer.GetSprite().getPosition().x ,m_height-5 });
    //}
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
