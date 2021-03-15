#pragma once
#include <SFML/Graphics.hpp>

struct Point {
    Point();
    Point(float _x, float _y);

    void draw(sf::RenderTarget& target);

    float x, y;
};

struct Rectangle {

    Rectangle();
    Rectangle(float _x, float _y, float _w, float _h);

    bool containsPoint(Point* p);

    float x, y, w, h;
};
