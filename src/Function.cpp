#include "Function.h"
#include "engine/Engine.h"

Function::Function() : Entity() {
    points.push_back(new Point(-3, -3));
    points.push_back(new Point(-2, -2));
    points.push_back(new Point(-1, -1));
    points.push_back(new Point(0, 0));
    points.push_back(new Point(1, 1));
    points.push_back(new Point(2, 2));
    points.push_back(new Point(3, 3));
    points.push_back(new Point(4, 4));
    points.push_back(new Point(5, 5));
    points.push_back(new Point(6, 6));
    points.push_back(new Point(7, 7));
    points.push_back(new Point(8, 8));
    points.push_back(new Point(9, 9));
    points.push_back(new Point(10, 10));
    points.push_back(new Point(11, 11));
    points.push_back(new Point(12, 12));
    points.push_back(new Point(13, 13));
    points.push_back(new Point(14, 14));
    points.push_back(new Point(15, 15));
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
            window.draw(create_line_thickness(x1, y1, x2, y2, line_thickness, color));
        }
        points[i]->plot(x1, y1);
    }
}

void Function::plot(double screen_x, double screen_y, double zoom) {
    this->zoom = zoom;
    this->origin_x = screen_x;
    this->origin_y = screen_y;
}
