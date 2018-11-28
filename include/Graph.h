#pragma once
#include "Entity.h"
#include "constants.h"

class Graph : public Entity {
private:
    const int LINE_THICKNESS = 5;
    sf::RectangleShape x_axis;
    sf::RectangleShape y_axis;

public:
    Graph();
    void render(sf::RenderWindow& window);
};
