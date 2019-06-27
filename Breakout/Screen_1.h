#pragma once
#include "cScreen.h"
#include "Board.h"
#include <chrono>
#include <fstream>
class Screen_1 : public cScreen
{
public:
	Screen_1();
	~Screen_1();

	int Run(sf::RenderWindow& window);

	Board board;

	bool move_paddle_left = false;
	bool move_paddle_right = false;

	std::chrono::time_point<std::chrono::high_resolution_clock> t1 = std::chrono::high_resolution_clock::now();
	std::chrono::time_point<std::chrono::high_resolution_clock> t2 = std::chrono::high_resolution_clock::now();
	std::chrono::time_point<std::chrono::high_resolution_clock> t3 = std::chrono::high_resolution_clock::now();
	std::chrono::time_point<std::chrono::high_resolution_clock> t4 = std::chrono::high_resolution_clock::now();

	int millis_pr_frame = 17;
	int das = 1;
	int high;
	sf::Text points;
	sf::Text highscore;
	sf::Font font;
	
	
};

