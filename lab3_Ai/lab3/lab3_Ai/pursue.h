#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include "Player.h"
#include "ScreenSize.h"
class pursue
{
	void setupdSprite();
	void predictionFunc();
	void pursueFunc(Player& t_player);
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Text m_text;
	sf::Font m_font;
	float maxSpeed = 4.0f;
	sf::Vector2f m_velocity;
	float m_maxSpeed = 4.0f;

public :
	pursue();
	~pursue();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time& t_deltatime, Player& t_player);

};

