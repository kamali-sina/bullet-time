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
    void setPosition(sf::Vector2f new_postion);
    sf::Vector2f getPosition();
    void setVelocity(sf::Vector2f new_velocity);
    sf::Vector2f getVelocity();

    private:
    float hp = BASE_MAX_HP;
    sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
    sf::Vector2f acceleration = sf::Vector2f(0.f, 0.f);
    sf::Vector2f position = sf::Vector2f(0.f, 0.f);
    sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(PLAYER_SIZE_X, PLAYER_SIZE_Y));

    float calculateNewVelocity(float velocity, float acceleration);
};

#endif