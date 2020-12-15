#pragma once
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include <vector>

#include "EquationInput.h"
#include "Function.h"
#include "FunctionHistory.h"
#include "constants.h"
#include "engine/Engine.h"
#include "engine/Entity.h"

class Graph : public Entity {
   private:
    // constants
    const int LINE_THICKNESS = 2;
    const double ZOOM_INCREMENT = 10;
    const double GRAPH_DEFAULT_ZOOM = 50;
    const double PAN_INCREMENT = 8;

    std::vector<std::shared_ptr<FunctionHistory>> function_history;
    std::vector<std::shared_ptr<Function>> functions;
    const sf::Color AXIS_COLOR = sf::Color::Green;
    double zoom = GRAPH_DEFAULT_ZOOM;

    sf::RectangleShape x_axis;
    sf::RectangleShape y_axis;

    sf::Font SourceCodePro;

    EquationInput equation_input;

    bool dragging = false;
    sf::Vector2i dragpos1;
    sf::Vector2i dragpos2;

   public:
    Graph();
    void step(sf::RenderWindow& window, sf::Event& event, bool poll);
    void plot_expression(std::string expression, double low = -50,
                         double high = 50);
    void render(sf::RenderWindow& window);
    void render_after(sf::RenderWindow& window);
};
