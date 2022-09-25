#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Player
{
	sf::Sprite m_sprite;
	sf::Texture m_texture;
public:

	void initilize();
	void movement();
	void render(sf::RenderWindow& t_window);


};

