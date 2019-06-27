#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
class Paddle
{
public:
	Paddle();
	Paddle(sf::Vector2f pos);
	~Paddle();

	sf::RectangleShape mid;
	sf::RectangleShape left;
	sf::RectangleShape right;

	int height = 20;
	std::vector<int> sizes = { 20, 50, 80, 120, 150 };
	int current_size = 1;
	void update_size();
	void move(int inc);
};

