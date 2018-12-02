#include "engine/Engine.h"

Engine::Engine()
    : entities(std::vector<Entity*>()),
      window(sf::VideoMode(SCREEN_HEIGHT, SCREEN_WIDTH), "hihi") {
    window.setFramerateLimit(FPS);
}

void Engine::run() {
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
    }
}

Entity* Engine::create_instance(Entity* entity) {
    this->entities.push_back(entity);
    return entity;
}
