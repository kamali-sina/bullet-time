#include "game.hpp"

using namespace std;

Game::Game(sf::RenderWindow &win) {
    window = &win;
}


void Game::run() {
    int cnt = 0;
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window->close();
            }

            // update event based components
            player.updateWithEvent(event);
        }

        // update components
        player.update();

        window->clear();
        // draw window
        player.draw(window);
        window->display();
    }
}