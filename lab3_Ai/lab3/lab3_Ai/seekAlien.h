#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "ScreenSize.h"
#include "Player.h"
class seekAlien
{

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_velocity;
	sf::CircleShape m_radius;
	float radiusCircle = 35.0f;
	float angle = 0.0f;
	float pi = 3.14159f;
	float speed = 2.0f;
	float maxSpeed = 4.0f;
	float distance;
	sf::Vector2f m_distanceVector;
	float m_rotation;
	float getRotation;
	float m_maxSpeed = 5.0f;
	//priv funcs under
public :
	//public variables and funcs as needed
	void update(sf::Time& t_deltatime,Player & t_player);
	void render(sf::RenderWindow& t_window);
	seekAlien();
	void setupAlien();
	void seek(sf::Time& t_deltaTime,Player & t_player);
	
	
	~seekAlien();
};

