#include "game.hpp"

using namespace std;

Game::Game(sf::RenderWindow &win) {
    window = &win;
    sf::RectangleShape *rect = new sf::RectangleShape(sf::Vector2f(1.f, 1000.f));
    rect->setPosition(sf::Vector2f(500.f, 0.f));
    rect->setFillColor(sf::Color::White);
    rect->setOutlineColor(sf::Color::White);
    
    lines.push_back(rect);
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

        // update component velocity
        player.update();

        // handle collisions and movable objects
        

        window->clear();
        // draw window
        player.draw(window);

        for (sf::RectangleShape *rect : lines) {
            window->draw(*rect);
        }

        
        window->display();
    }
}