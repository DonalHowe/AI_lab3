#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;
class Enemy
{
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	int counter = 0;
public :
	void initilize();
	void movement();
	void render(sf::RenderWindow& t_window);
};

