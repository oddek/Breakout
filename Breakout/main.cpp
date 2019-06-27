#include <SFML/Graphics.hpp>
#include "Screen_1.h"


int main()
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(1600, 1200), "Breakout");

	std::vector<cScreen*> Screens;
	int screen = 0;

	cScreen* s0 = new Screen_1();
	Screens.push_back(s0);
	while (screen <= 0)
	{
		screen = Screens[screen]->Run(window);

		if (screen == 2)
		{
			delete Screens[0];
			cScreen* s0 = new Screen_1();
			Screens.push_back(s0);
			screen = 0;
		}
	}
	return 0;
}


