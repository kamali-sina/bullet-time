#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "params.hpp"

class Player {
    public:
    Player();

    void updateWithEvent(sf::Event &event);
    void update();
    void draw(sf::RenderWindow *window);

    private:
    float hp = BASE_MAX_HP;
    float x_velocity = 0.f;
    float y_velocity = 0.f;
    float x_acceleration = 0.f;
    float y_acceleration = 0.f;
    float x_position = 0.f;
    float y_position = 0.f;
    sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(50,50));

    float calculateNewVelocity(float velocity, float acceleration);
};

#endif