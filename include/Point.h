#pragma once
#include "engine/Entity.h"

class Point : public Entity {
private:
    double graph_x;
    double graph_y;
    const double radius = 2;
    sf::Color color;
    sf::CircleShape point;

public:
    Point();
    Point(double graph_x, double graph_y);
    ~Point();
    void step();
    void render(sf::RenderWindow& window);

    void plot(double screen_x, double screen_y);
    void setColor(sf::Color color) { this->color = color; }
    
    double get_graph_x() { return graph_x; }
    double get_graph_y() { return graph_y; }

    void set_graph_x(double graph_x) { this->graph_x = graph_x; }
    void set_graph_y(double graph_y) { this->graph_y = graph_y; }
};

Point::Point() {
    this->point.setRadius(radius);
    this->point.setFillColor(color);
}

Point::Point(double graph_x, double graph_y)
    : graph_x(graph_x), graph_y(graph_y) {
    this->point.setRadius(radius);
    this->point.setFillColor(color);
}
Point::~Point() {}
void Point::step() {}

void Point::render(sf::RenderWindow& window) {
    window.draw(this->point);
}

// void Point::plot(double screen_x, double screen_y) {
//     this->point.setPosition(screen_x, screen_y);
// }
