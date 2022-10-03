#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class Player
{
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_postiion;
	sf::Vector2f m_velocity;
	const int MAX_SPEED = 2;
	float m_speed = 2;
	float accel = 0.05f;
	float decel = 0.02f;
public:
	sf::Sprite GetSprite();
	void setPostion(sf::Vector2f t_pos);
	void initilize();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);


};

