#include "game.hpp"

using namespace std;

Game::Game(sf::RenderWindow &win) {
    window = &win;
}


void Game::run() {
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window->close();
            }

            // update event based components
        }

        // update components

        window->clear();
        // draw window
        window->display();
    }
}