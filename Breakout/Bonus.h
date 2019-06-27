#pragma once
#include <SFML/Graphics.hpp>
class Board;
class Bonus : public sf::CircleShape
{
public:
	Bonus(int _type, sf::Vector2f pos);
	~Bonus();
	int type;

	bool update_position(Board& board);
};

