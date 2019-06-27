#include "Ball.h"
#include "Board.h"



Ball::Ball()
{
	setRadius(8);
	setFillColor(sf::Color::Color::White);
	setPosition(sf::Vector2f(500, 600));

	y_speed = ((double)rand()/RAND_MAX) * 5 + 4;
	x_speed = sqrt(pow(abs_speed, 2) - pow(y_speed, 2));
	

}


Ball::~Ball()
{
}

bool Ball::update_position(Board& board)
{
	
	sf::Vector2f new_pos = sf::Vector2f(getPosition().x + x_speed, getPosition().y + y_speed);
	if (new_pos.y > board.offset_y + board.height - 10) return false;
	//Check x bounds
	if (new_pos.x <= board.offset_x || new_pos.x >= board.offset_x + board.width) x_speed = -x_speed;
	//Check y bounds
	else if (new_pos.y <= board.offset_y || new_pos.y >= board.offset_y + board.height) y_speed = -y_speed;
	//Check paddle
	else if (getGlobalBounds().intersects(board.paddle.mid.getGlobalBounds())) y_speed = -abs(y_speed);
	else if (getGlobalBounds().intersects(board.paddle.left.getGlobalBounds()))
	{
		abs_speed += 4;
		y_speed = -abs(y_speed);
		x_speed = -sqrt(pow(abs_speed, 2) - pow(y_speed, 2));
	}
	else if (getGlobalBounds().intersects(board.paddle.right.getGlobalBounds()))
	{
		abs_speed += 4;
		y_speed = -abs(y_speed);
		x_speed = sqrt(pow(abs_speed, 2) - pow(y_speed, 2));
	}
					
	//Check bricks
	for (int i = 0; i < board.bricks.size(); i++)
	{
		if (board.bricks[i] != nullptr && getGlobalBounds().intersects(board.bricks[i]->getGlobalBounds()))
		{
			board.points += 100;
			auto rect_brick = board.bricks[i]->getGlobalBounds();
			sf::RectangleShape left(sf::Vector2f(3, rect_brick.height));
			left.setPosition(board.bricks[i]->getPosition());
			sf::RectangleShape right(sf::Vector2f(3, rect_brick.height));
			right.setPosition(board.bricks[i]->getPosition().x + rect_brick.width - 2, board.bricks[i]->getPosition().y);
			
			if(getGlobalBounds().intersects(left.getGlobalBounds()) ||
				getGlobalBounds().intersects(right.getGlobalBounds())) x_speed *=  -1;
			else y_speed *= -1;

			board.bricks[i]->health--;
			if (board.bricks[i]->getFillColor() == sf::Color(0x404040FF))
				board.bricks[i]->inner.setFillColor(board.bricks[i]->white_shades[board.bricks[i]->health]);
			if (board.bricks[i]->health <= 0)
			{
				int chance = rand() % 10;
				if (chance != 0) board.generate_bonus(board.bricks[i]->inner.getPosition());
				board.bricks[i] = nullptr;
				
			}
		}
	}
	move(sf::Vector2f(x_speed, y_speed));
	return true;
}

void Ball::update_speed(char dir_set)
{
	if (dir_set == 'y')
	{
		if (x_speed < 0)
		{
			x_speed =  - sqrt(pow(abs_speed, 2) - pow(y_speed, 2));
		}
		else
		{
			x_speed = sqrt(pow(abs_speed, 2) - pow(y_speed, 2));
		}
		
	}
	else
	{
		y_speed = sqrt(pow(abs_speed, 2) - pow(x_speed, 2));
	}
}