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
void Function::step() {}
void Function::render(sf::RenderWindow& window) {
    for (int i = 0; i < points.size(); i++) {
        double x1 = (points[i]->get_graph_x() * this->zoom) + origin_x;
        double y1 = -((points[i]->get_graph_y() * this->zoom)) + origin_y;
        double x2 = (points[i + 1]->get_graph_x() * this->zoom) + origin_x;
        double y2 = -((points[i + 1]->get_graph_y() * this->zoom)) + origin_y;

        if (i < points.size() - 1) {
            // window.draw(create_line_thickness(x1, y1, x2, y2, line_thickness, color));
        }
        points[i]->plot(x1, y1);
    }
}

void Function::plot(double screen_x, double screen_y, double zoom) {
    this->zoom = zoom;
    this->origin_x = screen_x;
    this->origin_y = screen_y;
}
