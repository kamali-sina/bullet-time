#ifndef _GAME_HPP
#define _GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "player.hpp"
#include "params.hpp"

class Game {
    public:
    Game(sf::RenderWindow &win);

    void run();

    private:
    sf::RenderWindow *window;
    Player player = Player();
};

#endif