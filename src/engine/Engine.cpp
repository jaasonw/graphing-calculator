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
            entities.at(i)->step();
        }
        window.clear();
        // render loop
        for (int i = 0; i < entities.size(); i++) {
            if (entities.at(i)->is_visible())
                entities.at(i)->render(window);
        }
        window.display();
        double fps = (1000000.0 / clock.restart().asMicroseconds());
        window.setTitle("FPS: " + std::to_string(fps));
    }
}

Entity* Engine::create_instance(Entity* entity) {
    entities.push_back(entity);
    return entity;
}
