#pragma once
#include "Function.h"
#include "constants.h"
#include "engine/Entity.h"
#include <vector>

class Graph : public Entity {
private:
    std::vector<Function*> functions;
    const int LINE_THICKNESS = 2;
    const double ZOOM_TO_PIXEL_SCALE = 20;
    const sf::Color AXIS_COLOR = sf::Color::Green;
    double zoom;

    sf::RectangleShape x_axis;
    sf::RectangleShape y_axis;

public:
    Graph();
    void render(sf::RenderWindow& window);
};
