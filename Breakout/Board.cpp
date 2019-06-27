#include "Board.h"



Board::Board()
{
	//Create board
	board.setSize(sf::Vector2f(width, height));
	board.setFillColor(sf::Color(0,0,0,225));
	board.setOutlineThickness(3);
	board.setOutlineColor(sf::Color::Color::Blue);
	board.setPosition(sf::Vector2f(offset_x, offset_y));
	//Create paddle
	Paddle p(sf::Vector2f(width / 2 - 60, 1000));
	paddle = p;
	//Create bricks
	generate_level();
	//Create ball
	Ball b;
	balls.push_back(b);
	//Generate paddles to draw lives
	sf::Vector2f pos(offset_x, 1150);
	for (int i = 0; i < 10; i++)
	{
		Paddle p(pos);
		//p.left.setPosition(pos);
		//p.mid.setPosition(pos.x + p.left.getSize().x, pos.y);
		//p.right.setPosition(pos.x + p.left.getSize().x + p.mid.getSize().x, pos.y);

		pos.x += p.left.getSize().x + p.mid.getSize().x + p.right.getSize().x + 10;
		life_drawings.push_back(p);
	}
}


Board::~Board()
{
}

void Board::move_paddle(char dir)
{
	int inc = 4;
	if (dir == 'l') inc = -4;

	//Check out of bounds
	if (inc < 0 && paddle.left.getPosition().x <= offset_x
		|| inc > 0 && paddle.right.getPosition().x + paddle.right.getSize().x >= offset_x + width)
		return;
	paddle.move(inc);
}

void Board::update()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].update_position(*this))
		{
			balls.erase(balls.begin() + i);
		}
	}
	if (balls.empty())
	{
		lives--;
		if (lives == 0) game_over = true;
		Ball b;
		balls.push_back(b);
	}
	/*if (!ball.update_position(*this))
	{
		lives--;
		if (lives == 0) game_over = true;
		Ball b;
		ball = b;
	}*/
	for (int i = 0; i < bonuses.size(); i++)
	{
		if (!bonuses[i].update_position(*this))
		{
			bonuses.erase(bonuses.begin() + i);
		}

	}
	for (int i = 0; i < bricks.size(); i++)
	{
		if (bricks[i] != nullptr && 
			(bricks[i]->getFillColor() != sf::Color(0x404040FF) &&
				bricks[i]->getFillColor() != sf::Color(0xff4f00aa))) return;
	}
	level++;
	if(lives < 7) lives += 3;
	if (level > max_level) game_over = true;
	else generate_level();
}

void Board::generate_level()
{
	bricks.clear();
	std::string l = std::to_string(level);
	std::string level = "img/level" + l + ".png";
	sf::Image img;
	img.loadFromFile(level);
	

	/*sf::Vector2f pos(offset_x, offset_y);
	int hor_bricks = 20;
	int vert_bricks = 12;
	for (int i = 0; i < vert_bricks; i++)
	{
		for (int j = 0; j < hor_bricks; j++)
		{
			sf::Color color = img.getPixel(j, i);
			if (color != sf::Color::Color::White) bricks.emplace_back(std::make_unique<Brick>(img.getPixel(j, i), width / hor_bricks, 500 / vert_bricks, pos));
			pos.x += width / hor_bricks;
		}
		pos.x = offset_x;
		pos.y += 500 / vert_bricks;
	}*/
	
	sf::Vector2f pos(offset_x, offset_y + 100);
	int hor_bricks = 20;
	int vert_bricks = 8;
	for (int i = 0; i < vert_bricks; i++)
	{
		for (int j = 0; j < hor_bricks; j++)
		{
			sf::Color color = img.getPixel(j, i);
			if (color != sf::Color::Color::White) bricks.emplace_back(std::make_unique<Brick>(img.getPixel(j, i), width / hor_bricks, 400 / vert_bricks, pos));	
			pos.x += width / hor_bricks;	
		}
		pos.x = offset_x;
		pos.y += 400 / vert_bricks;
	}
	
}

void Board::generate_bonus(sf::Vector2f pos)
{
	int type = rand() % 4;
	Bonus b(type, pos);
	bonuses.push_back(b);
}

void Board::handle_bonus(int type)
{
	switch (type)
	{
	case 0:
		if(lives < 10) lives++;
		break;
	case 1: 
		 if(paddle.current_size < 4) paddle.current_size += 1;
		 paddle.update_size();
		break;
	case 2:
		if(paddle.current_size > 0) paddle.current_size -= 1;
		paddle.update_size();
		break;
	case 3:
		Ball b1;
		Ball b2;
		balls.push_back(b1);
		balls.push_back(b2);
		break;
	}
}