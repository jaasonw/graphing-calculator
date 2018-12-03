#pragma once
#include "Point.h"
#include "engine/Entity.h"
#include "rpn/rpn.h"
#include "util.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <vector>

class Function : public Entity {
private:
    double interval_start = -10;
    double interval_end = 10;
    double point_frequency = 0.01;
    double zoom;
    double line_thickness = 2;
    sf::Color color = sf::Color::Red;
    // the screen x and y of the origin
    double origin_x;
    double origin_y;

    Queue<Token*> postfix;
    std::vector<Point*> points;
public:
    Function();
    ~Function();
    void step(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);

    // pass in the screen coordinates of the graph origin
    void plot(double screen_x, double screen_y, double zoom);

    sf::Color get_color(sf::Color color) { return this->color; }
    void set_color(sf::Color color) { this->color = color; }
};