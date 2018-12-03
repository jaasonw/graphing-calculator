#pragma once
#include "Entity.h"
#include "constants.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

class Engine {
private:
    static std::vector<Entity*> entities;
    sf::RenderWindow window;
    
public:
    Engine();
    void run();
    static Entity* add_entity(Entity* entity);
    static void remove_entity(Entity* entity);
};
