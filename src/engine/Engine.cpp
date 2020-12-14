#include "engine/Engine.h"

// static vars
std::list<std::shared_ptr<Entity>> Engine::entities =
    std::list<std::shared_ptr<Entity>>();

Engine::Engine() : window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "hihi") {
    window.setFramerateLimit(FPS);
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
        for (auto it = entities.begin(); it != entities.end(); ++it) {
            std::shared_ptr<Entity> ent = *it;
            ent->step(window, event, poll);
        }
        window.clear();
        // render loop
        for (auto it = entities.begin(); it != entities.end(); ++it) {
            std::shared_ptr<Entity> ent = *it;
            if (ent->is_visible()) ent->render(window);
        }
        // render loop
        for (auto it = entities.begin(); it != entities.end(); ++it) {
            std::shared_ptr<Entity> ent = *it;
            if (ent->is_visible()) ent->render_after(window);
        }
        window.display();
        double fps = (1000000.0 / clock.restart().asMicroseconds());
        window.setTitle("totally not scuffed graphing FPS: " +
                        std::to_string(fps));
    }
}

std::shared_ptr<Entity> Engine::add_entity(std::shared_ptr<Entity> entity) {
    entities.emplace_back(entity);
    return entity;
}

void Engine::remove_entity(std::shared_ptr<Entity> entity) {
    entities.remove(entity);
}