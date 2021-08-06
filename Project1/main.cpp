#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tools.h"
#include "QuadTree.h"

int main()
{

    srand(time(0));

    const int windowWidth = 800;
    const int windowHegiht = 800;
  
    Rectangle* boundary = new Rectangle(windowWidth, windowHegiht, windowWidth, windowHegiht);
    QuadTree* qt = new QuadTree(boundary, 4);

    for (size_t i = 0; i < 500; i++) {
        Point* p = new Point(rand() % windowWidth, rand() % windowHegiht);
        qt->Insert(p);
    }

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHegiht), "Quadtree", sf::Style::Close);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        qt->Draw(window);
        window.display();

    }

    return 0;
}