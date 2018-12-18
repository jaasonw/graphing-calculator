#include "engine/Engine.h"

// static vars
std::vector<Entity*> Engine::entities = std::vector<Entity*>();

Engine::Engine() : window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "hihi") {
    window.setFramerateLimit(FPS);
}

Engine::~Engine() {
    this->stop();
}

void Engine::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        bool poll = window.pollEvent(event);
        if (poll) {
            if (event.type == sf::Event::Closed) {
                window.close();
                this->stop();
            }
        }
        // step loop
        for (unsigned int i = 0; i < entities.size(); i++) {
            entities.at(i)->step(window, event, poll);
        }
        window.clear();
        // render loop
        for (unsigned int i = 0; i < entities.size(); i++) {
            if (entities.at(i)->is_visible())
                entities.at(i)->render(window);
        }
        // render loop
        for (unsigned int i = 0; i < entities.size(); i++) {
            if (entities.at(i)->is_visible())
                entities.at(i)->render_after(window);
        }
        window.display();
        double fps = (1000000.0 / clock.restart().asMicroseconds());
        window.setTitle("totally not scuffed graphing FPS: " + std::to_string(fps));
    }
}

void Engine::stop() {
    for (auto i = 0; i < entities.size(); i++) {
        delete entities[i];
    }
}

Entity* Engine::add_entity(Entity* entity) {
    entities.push_back(entity);
    return entity;
}

void Engine::remove_entity(Entity* entity) {
    for (unsigned int i = 0; i < entities.size(); i++) {
        if (entities[i] == entity) {
            // replace entity at i with last element
            entities[i] = entities[entities.size() - 1];
            // remove old last element
            entities.pop_back();
        }
    }
}