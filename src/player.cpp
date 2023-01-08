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

float Player::calculateNewVelocity(float velocity, float acceleration) {
    float new_velocity;
    if (acceleration != 0) {
        new_velocity = velocity + acceleration;
        if (new_velocity > TOP_SPEED) new_velocity = TOP_SPEED;
        else if (new_velocity < -TOP_SPEED) new_velocity = -TOP_SPEED;
    } else {
        new_velocity = sign(velocity) * max(abs(velocity) - FRICTION_VALUE, 0.f);
    }
    return new_velocity;
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
    y_velocity = calculateNewVelocity(y_velocity, y_acceleration);
    x_velocity = calculateNewVelocity(x_velocity, x_acceleration);

    float new_x_position = x_position + x_velocity;
    float new_y_position = y_position + y_velocity;

    if (new_x_position + PLAYER_SIZE_X > WIN_SIZE_X)  {
        new_x_position = WIN_SIZE_X - PLAYER_SIZE_X;
        x_velocity = (-sign(x_velocity)) * max(abs(x_velocity) - WALL_DAMP_EFFECT, 0.f);
    } else if (new_x_position < 0) {
        new_x_position = 0;
        x_velocity = (-sign(x_velocity)) * max(abs(x_velocity) - WALL_DAMP_EFFECT, 0.f);
    }

    if (new_y_position + PLAYER_SIZE_Y > WIN_SIZE_Y) {
        new_y_position = WIN_SIZE_Y - PLAYER_SIZE_Y;
        y_velocity = (-sign(y_velocity)) * max(abs(y_velocity) - WALL_DAMP_EFFECT, 0.f);
    } else if (new_y_position < 0) {
        new_y_position = 0;
        y_velocity = (-sign(y_velocity)) * max(abs(y_velocity) - WALL_DAMP_EFFECT, 0.f);
    }
    
    x_position = new_x_position;
    y_position = new_y_position;

    shape.setPosition(sf::Vector2f(x_position, y_position));
}

void Player::draw(sf::RenderWindow *window) {
    window->draw(shape);
}