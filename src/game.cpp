#include "game.hpp"

using namespace std;

Game::Game(sf::RenderWindow &win) {
    window = &win;
    
    Line* l1 = new Line(sf::Vector2f(500.f, 0.f), sf::Vector2f(500.f, 1000.f));
    lines.push_back(l1);

    l1 = new Line(sf::Vector2f(0.f, 500.f), sf::Vector2f(1000.f, 500.f));

    lines.push_back(l1);

    l1 = new Line(sf::Vector2f(250.f, 500.f), sf::Vector2f(500.f, 250.f));

    lines.push_back(l1);
}

void calculateCollision(sf::RectangleShape line, sf::Vector2f &position, sf::Vector2f &velocity) {
    
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
        // for (sf::RectangleShape *rect : lines) {
        //     window->draw(*rect);
        // }

        window->clear();
        // draw window
        player.draw(window);

        for (Line *line : lines) {
            line->draw(window);
        }

        
        window->display();
    }
}