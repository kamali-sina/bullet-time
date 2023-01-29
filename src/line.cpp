#include "line.hpp"

using namespace std;

float Line::getLenght() {
    return sqrt(((start.x - end.x) * (start.x - end.x)) + ((start.y - end.y) * (start.y - end.y)));
}

Line::Line(sf::Vector2f point1, sf::Vector2f point2) {
    start = point1;
    end = point2;
    sf::RectangleShape tempshape(sf::Vector2f(2.f, this->getLenght()));
    tempshape.setFillColor(sf::Color::Red);
    tempshape.setPosition(point1);
    if (end.x - start.x != 0) {
        float degree = atan((end.y - start.y) / (end.x - start.x)) * (180.0/PI);
        if (end.x > start.x) {
            tempshape.setRotation(degree - 90);
        } else {
            tempshape.setRotation(degree + 90);
        }
    }
    shape = tempshape;
}

void Line::draw(sf::RenderWindow *window) {
    window->draw(shape);
}