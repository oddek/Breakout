#include "Brick.h"

std::vector<sf::Color> Brick::white_shades = {sf::Color(0x00000000), sf::Color(0x404040AA), sf::Color(0x8b8989FF), sf::Color(0xffffffff) };

Brick::Brick(sf::Color _color, int width, int height, sf::Vector2f pos) :
	width(width), height(height)
{
	setSize(sf::Vector2f(width, height));
	setPosition(pos);
	setOutlineThickness(-3);
	setOutlineColor(sf::Color::Black);

	inner.setSize(sf::Vector2f(width*0.75, height*0.5));
	inner.setPosition(sf::Vector2f(pos.x + 0.125*width, pos.y + 0.25*height));
	
	if (_color == sf::Color(0x404040FF))
	{
		health = 3;
		setFillColor(_color);
		inner.setFillColor(white_shades[health]);
	}
	else if (_color == sf::Color(0x000000FF))
	{
		health = 100;
		setFillColor(sf::Color(0xff4f00aa));
		inner.setFillColor(sf::Color(0xff4f00ff));
	}
	else
	{
		inner.setFillColor(_color);
		setFillColor(sf::Color(_color.r, _color.g, _color.b, 0xAA));
	}
	
	
}


Brick::~Brick()
{
}
