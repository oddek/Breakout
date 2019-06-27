#include "Screen_1.h"



Screen_1::Screen_1()
{
	std::ifstream ist("highscore.txt");
	ist >> high;
	ist.close();

	font.loadFromFile("fonts/digital-7.ttf");
	points.setFont(font);
	points.setPosition(50, 25);
	points.setCharacterSize(50);
	points.setString("Points: 0");
	points.setFillColor(sf::Color::Color::White);

	highscore.setFont(font);
	highscore.setPosition(800, 25);
	highscore.setCharacterSize(50);
	highscore.setString("Highscore: " + std::to_string(high));
	highscore.setFillColor(sf::Color::Color::White);
}


Screen_1::~Screen_1()
{
}

int Screen_1::Run(sf::RenderWindow& window)
{
	bool pause = false;

	while (true)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Right:
					t1 = std::chrono::high_resolution_clock::now();
					move_paddle_right = true;
					break;
				case sf::Keyboard::Left:
					t1 = std::chrono::high_resolution_clock::now();
					move_paddle_left = true;
					break;
				case sf::Keyboard::P:
					pause = !pause;
					break;
					
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Right:
					move_paddle_right = false;
					break;
				case sf::Keyboard::Left:
					move_paddle_left = false;
				}
			}
		}
		
		if (move_paddle_left)
		{
			auto t2 = std::chrono::high_resolution_clock::now();
			auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);;
			if (milliseconds.count() > das)
			{
				board.move_paddle('l');
				t1 = std::chrono::high_resolution_clock::now();
				
			}
		}
		if (move_paddle_right)
		{
			auto t2 = std::chrono::high_resolution_clock::now();
			auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);;
			if (milliseconds.count() > das)
			{
				board.move_paddle('r');
				t1 = std::chrono::high_resolution_clock::now();

			}
		}

		t4 = std::chrono::high_resolution_clock::now();
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);;
		if (milliseconds.count() > millis_pr_frame)
		{
			if(!pause) board.update();
			t3 = std::chrono::high_resolution_clock::now();

		}
		
		points.setString("Points: " + std::to_string(board.points));

		if (board.game_over)
		{
			if (board.points > high)
			{
				std::ofstream ost("highscore.txt");
				ost << board.points;
				ost.close();
			}
			return 2;
		}
		window.clear(sf::Color(0x000d1aff));
		
		window.draw(board.board);
		window.draw(highscore);
		window.draw(points);
		for(auto i : board.balls) window.draw(i);
		window.draw(board.paddle.left);
		window.draw(board.paddle.mid);
		window.draw(board.paddle.right);
		for (int i = 0; i < board.lives; i++)
		{
			window.draw(board.life_drawings[i].left);
			window.draw(board.life_drawings[i].mid);
			window.draw(board.life_drawings[i].right);
		}
		for (auto& i : board.bricks)
		{
			if (i.get() == nullptr) continue;
			window.draw(*i.get());
			window.draw(i->inner);
		}
		for (auto i : board.bonuses) window.draw(i);
		window.display();
	}
}
