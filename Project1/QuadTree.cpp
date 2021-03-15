#include "QuadTree.h"
#include<iostream>

QuadTree::QuadTree()
{
    boundary = Rectangle(200, 200, 200, 200);
    capacity = 1;
    divided = false;
}

QuadTree::QuadTree(Rectangle* _boundary, unsigned int _capacity) {

    boundary = *_boundary;
    capacity = _capacity;
    divided = false;
}

void QuadTree::Insert(Point* p) {
    
    if (!boundary.containsPoint(p)) {
        return;
    }

    if (points.size() != capacity) {
        points.push_back(p);
    }
    else {

        if (!divided) {
            Subdivide();
        }

        northEast->Insert(p);
        northWest->Insert(p);
        southEast->Insert(p);
        southWest->Insert(p);

    }
}

void QuadTree::Subdivide() {

    int x = boundary.x;
    int y = boundary.y;
    int w = boundary.w / 2;
    int h = boundary.h / 2;

    Rectangle* ne = new Rectangle(x + w, y - h, w, h);
    northEast = new QuadTree(ne, capacity);
    Rectangle* nw = new Rectangle(x - w, y - h, w, h);
    northWest = new QuadTree(nw, capacity);
    Rectangle* se = new Rectangle(x + w, y + h, w, h);
    southEast = new QuadTree(se, capacity);
    Rectangle* sw = new Rectangle(x - w, y + h, w, h);
    southWest = new QuadTree(sw, capacity);

    divided = true;

}

void QuadTree::Draw(sf::RenderTarget& target) {

    for (auto& p : points) {
        p->draw(target);
    }

    sf::RectangleShape* Rect = new sf::RectangleShape();
    Rect->setPosition(sf::Vector2f(boundary.x, boundary.y));
    Rect->setOrigin(sf::Vector2f(boundary.w, boundary.h));
    Rect->setSize(sf::Vector2f(boundary.w*2, boundary.h*2));
    Rect->setFillColor(sf::Color(0, 0, 0, 0));
    Rect->setOutlineColor(sf::Color::White);
    Rect->setOutlineThickness(1);
    target.draw(*Rect);
    delete Rect;

    if (divided) {
        northEast->Draw(target);
        northWest->Draw(target);
        southEast->Draw(target);
        southWest->Draw(target);
    }
};