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

	return 0;
}
