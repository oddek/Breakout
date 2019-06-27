#pragma once
#include <SFML/Graphics.hpp>
class cScreen
{
public:
	cScreen();
	~cScreen();

	virtual int Run(sf::RenderWindow& window) = 0;
};

