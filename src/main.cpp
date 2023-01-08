#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"

using namespace std;

int main()
{
    sf::RenderWindow win(sf::VideoMode(WIN_SIZE_X, WIN_SIZE_Y), WIN_NAME);
    win.setFramerateLimit(60);

	Game game = Game(win);

    game.run();

    // game.run();

	// sf::Font font;

	// if (!font.loadFromFile("RubikBubbles-Regular.ttf")) {
	// 	cout<<"Error: font could not be loaded!"<<endl;
	// 	exit(0);
	// }

	// while (window.isOpen())
	// {
	// 	sf::Event event;
	// 	while (window.pollEvent(event)) {
	// 		// update base on events
    //     }

	// 	window.clear();
	// 	// draw window
	// 	window.display();
	// }

	return 0;
}
