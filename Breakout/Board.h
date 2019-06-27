#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "Bonus.h"
#include <memory>
#include <string>
class Board
{
public:
	Board();
	~Board();

	
	std::vector<Ball> balls;
	Paddle paddle;
	std::vector<std::unique_ptr<Brick>> bricks;

	bool game_over = false;

	int width = 1580;
	int height = 1000;
	
	int level = 3;
	int points = 0;
	int lives = 3;
	int max_level = 5;
	std::vector<Paddle> life_drawings;
	std::vector<Bonus> bonuses;
	int offset_x = 10;
	int offset_y = 100;

	sf::Texture back_tex;
	sf::Sprite back_sprite;
	sf::RectangleShape board;

	void move_paddle (char dir);
	void update();

	void handle_bonus(int type);
	void generate_bonus(sf::Vector2f pos);
	void generate_level();
};

