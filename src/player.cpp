#include "player.hpp"

using namespace std;

int sign(float number) {
    if (number > 0) return 1;
    if (number < 0) return -1;
    return 0;
}

Player::Player() {
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(position);
}

void Player::setPosition(sf::Vector2f new_postion) {
    shape.setPosition(position);
}

sf::Vector2f Player::getPosition() {
    return shape.getPosition();
}

void Player::setVelocity(sf::Vector2f new_velocity) {
    velocity = new_velocity;
}

sf::Vector2f Player::getVelocity() {
    return velocity;
}

float Player::calculateNewVelocity(float _velocity, float _acceleration) {
    float new_velocity;
    if (_acceleration != 0) {
        new_velocity = _velocity + _acceleration;
        if (new_velocity > TOP_SPEED) new_velocity = TOP_SPEED;
        else if (new_velocity < -TOP_SPEED) new_velocity = -TOP_SPEED;
    } else {
        new_velocity = sign(_velocity) * max(abs(_velocity) - FRICTION_VALUE, 0.f);
    }
    return new_velocity;
}

void Player::updateWithEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            acceleration.y = -ACCELERATION_VALUE;
        } else if (event.key.code == sf::Keyboard::Down) {
            acceleration.y = ACCELERATION_VALUE;
        } else if (event.key.code == sf::Keyboard::Right) {
            acceleration.x = ACCELERATION_VALUE;
        } else if (event.key.code == sf::Keyboard::Left) {
            acceleration.x = -ACCELERATION_VALUE;
        }
    } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) {
            acceleration.y = 0;
        } else if (event.key.code == sf::Keyboard::Down) {
            acceleration.y = 0;
        } else if (event.key.code == sf::Keyboard::Right) {
            acceleration.x = 0;
        } else if (event.key.code == sf::Keyboard::Left) {
            acceleration.x = 0;
        }
    }
}

void Player::update() {
    velocity.y = calculateNewVelocity(velocity.y, acceleration.y);
    velocity.x = calculateNewVelocity(velocity.x, acceleration.x);

    float new_x_position = position.x + velocity.x;
    float new_y_position = position.y + velocity.y;

    if (new_x_position + PLAYER_SIZE_X > WIN_SIZE_X)  {
        new_x_position = WIN_SIZE_X - PLAYER_SIZE_X;
        velocity.x = (-sign(velocity.x)) * max(abs(velocity.x) - WALL_DAMP_EFFECT, 0.f);
    } else if (new_x_position < 0) {
        new_x_position = 0;
        velocity.x = (-sign(velocity.x)) * max(abs(velocity.x) - WALL_DAMP_EFFECT, 0.f);
    }

    if (new_y_position + PLAYER_SIZE_Y > WIN_SIZE_Y) {
        new_y_position = WIN_SIZE_Y - PLAYER_SIZE_Y;
        velocity.y = (-sign(velocity.y)) * max(abs(velocity.y) - WALL_DAMP_EFFECT, 0.f);
    } else if (new_y_position < 0) {
        new_y_position = 0;
        velocity.y = (-sign(velocity.y)) * max(abs(velocity.y) - WALL_DAMP_EFFECT, 0.f);
    }
    
    position.x = new_x_position;
    position.y = new_y_position;

    shape.setPosition(position);
}

void Player::draw(sf::RenderWindow *window) {
    window->draw(shape);
}