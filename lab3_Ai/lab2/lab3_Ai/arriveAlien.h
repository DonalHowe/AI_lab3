#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include<iostream>
#include "ScreenSize.h"


class arriveAlien
{
	sf::Texture m_texture;
	sf::Sprite m_sprite;
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
	arriveAlien();
	~arriveAlien();
	void update(sf::Time& t_deltaTime,Player & t_player);
	void render(sf::RenderWindow& t_window);
};

