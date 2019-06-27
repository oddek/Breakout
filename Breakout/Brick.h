#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Brick : public sf::RectangleShape
{
public:
	Brick(sf::Color _color, int width, int height, sf::Vector2f pos);
	~Brick();
	
	int health = 1;
	sf::RectangleShape inner;

	static std::vector<sf::Color> white_shades;

	int height;
	int width;
};

