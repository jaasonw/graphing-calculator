#include "engine/Entity.h"

#include "engine/Engine.h"

Entity::Entity() : screen_x(0), screen_y(0) {
    Engine::add_entity(std::shared_ptr<Entity>(this));
}
Entity::~Entity() { Engine::remove_entity(std::shared_ptr<Entity>(this)); }

void Entity::step(sf::RenderWindow& window, sf::Event& event, bool poll) {}
void Entity::render(sf::RenderWindow& window) {}
void Entity::render_after(sf::RenderWindow& window) {}