#ifndef _LINE_HPP
#define _LINE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "params.hpp"

//TODO: line 500,250 -> 250,500 does not work
class Line {
public:
    Line(sf::Vector2f point1, sf::Vector2f point2);
    float getLenght();
    void draw(sf::RenderWindow *window);

    sf::Vector2f start;
    sf::Vector2f end;
    sf::RectangleShape shape;
};

#endif