#pragma once
#include "Function.h"
#include "constants.h"
#include "engine/Engine.h"
#include "engine/Entity.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <vector>

class Graph : public Entity {
private:
    // constants
    const int LINE_THICKNESS = 2;
    const double ZOOM_INCREMENT = 10;
    const double GRAPH_DEFAULT_ZOOM = 50;
    const double PAN_INCREMENT = 8;

    std::vector<Function*> functions;
    const sf::Color AXIS_COLOR = sf::Color::Green;
    double zoom = GRAPH_DEFAULT_ZOOM;

    sf::RectangleShape x_axis;
    sf::RectangleShape y_axis;

    sf::Font SourceCodePro;

public:
    Graph();
    void step(sf::RenderWindow& window, const sf::Event& event);
    void render(sf::RenderWindow& window);
};
