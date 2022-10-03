#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "ScreenSize.h"
using namespace std;
class Enemy
{
	sf::Texture m_texture; 
	sf::Sprite m_sprite;
	sf::CircleShape radius;
	float radiusF = 100.0f;
	
	sf::VertexArray m_WanderLine{ sf::Lines };
	sf::Vector2f m_linePT;

	bool m_alive = true;
	bool m_tracerStatus = false;

	sf::Font m_font;
	sf::Text m_name;
	void kinematicWander(sf::Time& t_deltaTime);
	int m_offset = 16;
	float RadianAngle = 0;
	float m_angle = 0.0f;
	float m_pi = 3.1415f;
	sf::Vector2f m_velocity;
	float m_speed = 2.0f;
	float m_MaxSpeed = 5.0f;
	int m_randInt = 0;
	void setupSprites();
	void randomNum();
	void boundryCheck();

public:

	void update(sf::Time& t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void initilise();
	Enemy();
};

