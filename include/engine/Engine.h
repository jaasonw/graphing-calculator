#pragma once
#include "Entity.h"
#include "constants.h"
#include "rpn/stack_queue/lib/linked_list/List.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

class Engine {
private:
    static List<Entity*> entities;
    sf::RenderWindow window;

public:
    Engine();
    void run();
    static Entity* add_entity(Entity* entity);
    static void remove_entity(Entity* entity);
};
