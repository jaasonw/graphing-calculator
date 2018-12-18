#pragma once
#include "engine/Entity.h"
#include "rpn/rpn.h"
#include "util.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <iostream>
#include <string>
#include <vector>

class Function : public Entity {
private:
    double interval_start = -50;
    double interval_end = 50;
    double point_frequency = 0.1;
    double zoom;
    double line_thickness = 2;
    sf::Color color = sf::Color::Red;
    // the screen x and y of the origin
    double origin_x;
    double origin_y;

    std::string function_string;
    Queue<Token*> postfix;
    std::vector<sf::Vector2f> points;

    bool done_plotting = false;

public:
    Function();
    Function(std::string function_string);
    ~Function();
    void step(sf::RenderWindow& window, sf::Event& event, bool poll);
    void render(sf::RenderWindow& window);

    // pass in the screen coordinates of the graph origin
    void plot(double screen_x, double screen_y, double zoom);

    sf::Color get_color() { return this->color; }
    void set_color(sf::Color color) { this->color = color; }

    std::string get_string() { return this->function_string; }

    void set_start(double interval_start){ this->interval_start = interval_start; }
    void set_end(double interval_end){ this->interval_end = interval_end; }

    void set_bounds(double low, double high);

    void update_graph();
};