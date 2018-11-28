#pragma once
#include "constants.h"
#include "engine/Entity.h"

class Graph : public Entity {
private:
    const int LINE_THICKNESS = 5;
    sf::RectangleShape x_axis;
    sf::RectangleShape y_axis;

public:
    Graph();
    void render(sf::RenderWindow& window);
};
