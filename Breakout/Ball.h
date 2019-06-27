#pragma once
#define _USE_MATH_DEFINES
#include <SFML\Graphics.hpp>
#include <cmath>
#include <math.h>
class Board;

class Ball : public sf::CircleShape
{
public:
	Ball();
	~Ball();

	double y_speed;
	double x_speed;
	double abs_speed = 11.3;
	//If return false, ball under paddle
	bool update_position(Board& board);
	void update_speed(char dir_set);
};

