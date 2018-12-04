#include "Function.h"
#include "engine/Engine.h"
#include <iostream>

Function::Function() : Entity() {
    for (double i = interval_start; i < interval_end; i += point_frequency) {
        points.push_back(new Point(i, sin(i)));
    }
}
Function::~Function() {
    for (auto point : points) {
        delete point;
    }
}
void Function::step(sf::RenderWindow& window, const sf::Event& event) {}
void Function::render(sf::RenderWindow& window) {
    for (unsigned int i = 0; i < points.size(); i++) {
        double x = (points[i]->get_graph_x() * this->zoom) + origin_x;
        double y = -((points[i]->get_graph_y() * this->zoom)) + origin_y;
        points[i]->plot(x, y);
    }
}

void Function::plot(double screen_x, double screen_y, double zoom) {
    this->zoom = zoom;
    this->origin_x = screen_x;
    this->origin_y = screen_y;
}
