#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include<iostream>
#include "ScreenSize.h"



class arriveAlien
{
	sf::Vertex m_leftLine[2];
	sf::Vertex m_rightLine[2];
	float leftlinePtX;
	float leftlinePtY;
	float rightlinePtX;
	float rightlinePtY;

	sf::Texture m_texture;
	
	sf::Text m_text;
	sf::Font m_font;
	float angle = 0.0f;
	float pi = 3.14159f;
	float distancefromPt=0.0f;
	float m_rot=0.0f;
	float initialRot=0.0f;
	static constexpr float MAX_SPEED = 4.0f;
	sf::Vector2f m_velocity{0.0f,0.0f};
	float timeToTarget = 2.5f;
	void setupSprite();
	void arrive(sf::Time & t_deltaTime,Player & t_player);
public:
	sf::Sprite m_sprite;
	arriveAlien();
	~arriveAlien();
	void update(sf::Time& t_deltaTime,Player & t_player);
	void render(sf::RenderWindow& t_window);
};

