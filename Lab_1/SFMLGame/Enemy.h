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
	void update(double dt);
	void render(sf::RenderWindow& t_window);
};

