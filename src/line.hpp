#ifndef _LINE_HPP
#define _LINE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class line {
public:
    line(sf::Vector2f point1, sf::Vector2f point2);

    sf::Vector2f start;
    sf::Vector2f end;
    sf::RectangleShape shape;
};

#endif