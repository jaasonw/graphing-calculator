#include "engine/Entity.h"
#include "engine/Engine.h"

Entity::Entity() : screen_x(0), screen_y(0) {
    Engine::add_entity(this);
}
Entity::~Entity() {
    Engine::remove_entity(this);
}

void Entity::step(sf::RenderWindow& window, const sf::Event& event) {}
void Entity::step(sf::RenderWindow& window, sf::Event& event) {}
void Entity::render(sf::RenderWindow& window) {}
void Entity::render_after(sf::RenderWindow& window) {}