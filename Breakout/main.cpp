#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <Windows.h>
#include "Screen_1.h"


int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(1600, 1200), "Breakout");

	std::vector<cScreen*> Screens;
	int screen = 0;

	cScreen* s0 = new Screen_1();
	Screens.push_back(s0);
	while (screen <= 0)
	{
		if (screen < 0) break;
		screen = Screens[screen]->Run(window);

		if (screen == 2)
		{
			delete Screens[0];
			cScreen* s0 = new Screen_1();
			Screens.push_back(s0);
			screen = 0;
		}
	}
	PostMessage(GetConsoleWindow(), WM_CLOSE, 0, 0);
	return 0;
}


