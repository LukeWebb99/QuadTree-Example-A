#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tools.h"
#include "QuadTree.h"

int main()
{

    srand(time(0));

  
    Rectangle* boundary = new Rectangle(400, 400, 400, 400);
    QuadTree* qt = new QuadTree(boundary, 4);

    for (size_t i = 0; i < 500; i++) {
        Point* p = new Point(rand() % 400, rand() % 400);
        qt->Insert(p);
    }

    sf::RenderWindow window(sf::VideoMode(400, 400), "");
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