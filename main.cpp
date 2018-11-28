#include "include/constants.h"
#include "include/Entity.h"
#include "include/Graph.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    std::vector<Entity*> entities = std::vector<Entity*>();
    sf::RenderWindow window(sf::VideoMode(SCREEN_HEIGHT, SCREEN_WIDTH), "hihi");
    window.setFramerateLimit(FPS);

    entities.push_back(new Graph());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // step loop
        for (int i = 0; i < entities.size(); i++) {
            entities.at(i)->step();
        }

        window.clear();

        // render loop
        for (int i = 0; i < entities.size(); i++) {
            entities.at(i)->render(window);
        }
        
        window.display();
    }
    return 0;
}