#include "Function.h"
#include "engine/Engine.h"

Function::Function() : Entity() {
    points.push_back(new Point(0, 0));
    points.push_back(new Point(0, 1));
    points.push_back(new Point(0, 2));
    points.push_back(new Point(0, 3));
    points.push_back(new Point(0, 4));
    points.push_back(new Point(0, 5));
}
Function::~Function() {
    for (auto point : points) {
        delete point;
    }
}
void Function::step() {}
void Function::render(sf::RenderWindow& window) {
    for (auto point : points) {
        point->plot(point->get_graph_x() + (origin_x * this->zoom),
                    point->get_graph_y() + (origin_y * this->zoom));
    }
}

void Function::plot(double screen_x, double screen_y, double zoom) {
    this->zoom = zoom;
    this->origin_x = screen_x;
    this->origin_y = screen_y;
}