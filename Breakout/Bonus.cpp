#include "Bonus.h"
#include "Board.h"


Bonus::Bonus(int _type, sf::Vector2f pos): type(_type)
{
	setPosition(pos);
	setRadius(30);
	switch (type)	{
	//Ekstra liv
	case 0:
		setFillColor(sf::Color::Color::Green);
		break;
	//Longer paddle
	case 1:
		setFillColor(sf::Color::Color::Blue);
		break;
	//Shorter paddle
	case 2:
		setFillColor(sf::Color::Color::Red);
		break;
	//More balls
	case 3:
		setFillColor(sf::Color::Color::White);
		break;
	}
}


Bonus::~Bonus()
{
}

bool Bonus::update_position(Board& board)
{
	move(0, 5);
	if (getPosition().y > board.offset_y + board.height) return false;
	if (getGlobalBounds().intersects(board.paddle.left.getGlobalBounds()) ||
		getGlobalBounds().intersects(board.paddle.mid.getGlobalBounds()) ||
		getGlobalBounds().intersects(board.paddle.right.getGlobalBounds()))
	{
		board.handle_bonus(type);
		return false;
	}
	return true;
}