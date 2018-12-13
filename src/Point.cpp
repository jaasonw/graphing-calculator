#include "Point.h"

Point::Point() : Entity() {
    this->point.setRadius(RADIUS);
    this->point.setFillColor(color);
    this->point.setOrigin(sf::Vector2f(RADIUS, RADIUS));
}

Point::Point(double graph_x, double graph_y, sf::Color color)
    : graph_x(graph_x), graph_y(graph_y), color(color) {
    this->point.setRadius(RADIUS);
    this->point.setFillColor(color);
    this->point.setOrigin(sf::Vector2f(RADIUS, RADIUS));
}
Point::~Point() {}
void Point::step(sf::RenderWindow& window, sf::Event& event, bool poll) {
    if (this->point.getPosition().x < 0 || this->point.getPosition().x > SCREEN_WIDTH)
        this->set_visible(false);
    else if (this->point.getPosition().y < 0 || this->point.getPosition().y > SCREEN_HEIGHT)
        this->set_visible(false);
    else
        this->set_visible(true);
}

void Point::render(sf::RenderWindow& window) { window.draw(this->point); }

void Point::plot(double screen_x, double screen_y) {
    this->point.setPosition(screen_x, screen_y);
}