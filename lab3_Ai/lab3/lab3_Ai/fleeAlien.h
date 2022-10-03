#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Player.h"
#include "ScreenSize.h"

class fleeAlien
{
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	float angle = 0.0f;
	float pi = 3.14159f;
	float distancefromPt = 0.0f;
	float m_rot = 0.0f;
	float initialRot = 0.0f;
	static constexpr float MAX_SPEED = 1.2f;
	sf::Vector2f m_velocity{ 0.0f,0.0f };
	float timeToTarget = 2.5f;
	void setupSprite();
	void flee(sf::Time& t_deltaTime, Player& t_player);
	void boundryCheck();
	int m_offset = 16;
public:
	fleeAlien();
	~fleeAlien();
	void update(sf::Time& t_deltaTime, Player& t_player);
	void render(sf::RenderWindow& t_window);
};

