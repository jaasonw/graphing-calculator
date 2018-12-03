#include "engine/Entity.h"
#include "engine/Engine.h"

Entity::Entity() : screen_x(0), screen_y(0) {
    Engine::add_entity(this);
}
Entity::~Entity() {
    Engine::remove_entity(this);
}

void Entity::step() {}
void Entity::render(sf::RenderWindow& window) {}