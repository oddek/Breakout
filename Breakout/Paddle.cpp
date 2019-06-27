#include "Paddle.h"

Paddle::Paddle(){}

Paddle::Paddle(sf::Vector2f pos)
{
	left.setFillColor(sf::Color::Color::Red);
	left.setSize(sf::Vector2f(15, height));
	left.setPosition(pos);

	pos.x += left.getSize().x;
	mid.setFillColor(sf::Color::Color(0x808080ff));
	mid.setSize(sf::Vector2f(sizes[1], height));
	mid.setPosition(pos);

	pos.x += mid.getSize().x;
	right.setFillColor(sf::Color::Color::Red);
	right.setSize(sf::Vector2f(15, height));
	right.setPosition(pos);
}


Paddle::~Paddle()
{
}

void Paddle::move(int inc)
{
	
	left.move(sf::Vector2f(inc, 0));
	mid.move(sf::Vector2f(inc, 0));
	right.move(sf::Vector2f(inc, 0));
}

void Paddle::update_size()
{
	mid.setSize(sf::Vector2f(sizes[current_size], height));
	right.setPosition(mid.getPosition().x + sizes[current_size], right.getPosition().y);
}
