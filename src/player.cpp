#include "player.hpp"

using namespace std;

int sign(float number) {
    if (number > 0) return 1;
    if (number < 0) return -1;
    return 0;
}

Player::Player() {
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(x_position, y_position));
}


void Player::updateWithEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            y_acceleration = -ACCELERATION_VALUE;
        } else if (event.key.code == sf::Keyboard::Down) {
            y_acceleration = ACCELERATION_VALUE;
        } else if (event.key.code == sf::Keyboard::Right) {
            x_acceleration = ACCELERATION_VALUE;
        } else if (event.key.code == sf::Keyboard::Left) {
            x_acceleration = -ACCELERATION_VALUE;
        }
    } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) {
            y_acceleration = 0;
        } else if (event.key.code == sf::Keyboard::Down) {
            y_acceleration = 0;
        } else if (event.key.code == sf::Keyboard::Right) {
            x_acceleration = 0;
        } else if (event.key.code == sf::Keyboard::Left) {
            x_acceleration = 0;
        }
    }
}

void Player::update() {
    if (y_acceleration != 0) {
        // y_velocity = sign(y_velocity) * min(abs(y_velocity + y_acceleration), TOP_SPEED);
        y_velocity += y_acceleration;
        if (y_velocity > TOP_SPEED) y_velocity = TOP_SPEED;
        else if (y_velocity < -TOP_SPEED) y_velocity = -TOP_SPEED;
    } else {
        y_velocity = sign(y_velocity) * max(abs(y_velocity) - (ACCELERATION_VALUE / 4), 0.f);
    }

    if (x_acceleration != 0) {
        // x_velocity = sign(x_velocity) * min(abs(x_velocity + x_acceleration), TOP_SPEED);
        x_velocity += x_acceleration;
        if (x_velocity > TOP_SPEED) x_velocity = TOP_SPEED;
        else if (x_velocity < -TOP_SPEED) x_velocity = -TOP_SPEED;
    } else {
        x_velocity = sign(x_velocity) * max(abs(x_velocity) - (ACCELERATION_VALUE / 4), 0.f);
    }

    x_position += x_velocity;
    y_position += y_velocity;

    shape.setPosition(sf::Vector2f(x_position, y_position));
}

void Player::draw(sf::RenderWindow *window) {
    window->draw(shape);
}