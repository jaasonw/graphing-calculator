#pragma once
#include "Entity.h"
#include "constants.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

class Engine {
private:
    std::vector<Entity*> entities;
    sf::RenderWindow window;

public:
    Engine();
    void run();
    Entity* create_instance(Entity* entity);
};
