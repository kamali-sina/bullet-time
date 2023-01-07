#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#define BASE_MAX_HP 100.f

class Player {
    public:
    Player();

    private:
    float hp = BASE_MAX_HP;
};

#endif