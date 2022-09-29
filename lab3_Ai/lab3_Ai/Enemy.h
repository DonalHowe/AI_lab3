#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;
class Enemy
{
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	int counter = 0;
	int choice = 0;
public :
	sf::Sprite GetSprite();
	void initilize();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
};

