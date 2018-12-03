#include "engine/Engine.h"

List<Entity*> Engine::entities = List<Entity*>();

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
        for (auto it = entities.begin(); it != NULL; it++) {
            (*it)->step();
        }
        window.clear();
        // render loop
        for (auto it = entities.begin(); it != NULL; it++) {
            (*it)->render(window);
        }
        window.display();
        double fps = (1000000.0 / clock.restart().asMicroseconds());
        window.setTitle("FPS: " + std::to_string(fps));
    }
}

Entity* Engine::add_entity(Entity* entity) {
    entities.insert_head(entity);
    
    // entities.insert_after(entities.begin(), entity);
    return entity;
}

void Engine::remove_entity(Entity* entity) {
    entities.del(entities.search(entity));
}