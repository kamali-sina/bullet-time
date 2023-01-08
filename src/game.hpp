#ifndef _GAME_HPP
#define _GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "player.hpp"

#define WIN_SIZE_X 1000
#define WIN_SIZE_Y 1000
#define WIN_NAME   "Bullet Time"

class Game {
    public:
    Game(sf::RenderWindow &win);

    void run();

    private:
    sf::RenderWindow *window;
    Player player = Player();
};

#endif