#include "engine/Entity.h"

Entity::Entity() : screen_x(0), screen_y(0) {}
Entity::~Entity() {}

void Entity::step() {}
void Entity::render(sf::RenderWindow& window) {}