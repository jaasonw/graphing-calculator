#include "engine/Entity.h"
#include "engine/Engine.h"

Entity::Entity() : screen_x(0), screen_y(0) {
    Engine::create_instance(this);
}
Entity::~Entity() {}

void Entity::step() {}
void Entity::render(sf::RenderWindow& window) {}