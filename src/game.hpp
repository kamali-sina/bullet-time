#ifndef _GAME_HPP
#define _GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "params.hpp"
#include "line.hpp"

class Game {
    public:
    Game(sf::RenderWindow &win);
    void handleCollision();
    void run();

    private:
    sf::RenderWindow *window;
    Player player = Player();
    std::vector<Line*> lines;
};

#endif