#include "engine/Engine.h"

std::vector<Entity*> Engine::entities = std::vector<Entity*>();

Engine::Engine() : window(sf::VideoMode(SCREEN_HEIGHT, SCREEN_WIDTH), "hihi") {
    window.setFramerateLimit(FPS);
}

void Engine::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // step loop
        for (int i = 0; i < entities.size(); i++) {
            entities.at(i)->step(window);
        }
        window.clear();
        // render loop
        for (int i = 0; i < entities.size(); i++) {
            if (entities.at(i)->is_visible())
                entities.at(i)->render(window);
        }
        window.display();
        double fps = (1000000.0 / clock.restart().asMicroseconds());
        window.setTitle("totally not scuffed graphing FPS: " + std::to_string(fps));
    }
}

Entity* Engine::add_entity(Entity* entity) {
    entities.push_back(entity);
    return entity;
}

void Engine::remove_entity(Entity* entity) {
    for (int i = 0; i < entities.size(); i++) {
        if (entities[i] == entity) {
            // replace entity at i with last element
            entities[i] = entities[entities.size() - 1];
            // remove old last element
            entities.pop_back();
        }
    }
    entities.pop_back();
}