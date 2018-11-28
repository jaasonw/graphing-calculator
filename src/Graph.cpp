#include "Graph.h"
#include "constants.h"

Graph::Graph() {
    this->set_x(SCREEN_WIDTH / 2);
    this->set_y(SCREEN_HEIGHT / 2);
    
    this->x_axis = sf::RectangleShape(sf::Vector2f(SCREEN_WIDTH, LINE_THICKNESS));
    this->y_axis = sf::RectangleShape(sf::Vector2f(LINE_THICKNESS, SCREEN_HEIGHT));

    this->x_axis.setFillColor(AXIS_COLOR);
    this->y_axis.setFillColor(AXIS_COLOR);
}

void Graph::render(sf::RenderWindow& window) {
    // set positions
    this->x_axis.setOrigin(sf::Vector2f(this->x_axis.getSize().x / 2, this->x_axis.getSize().y / 2));
    this->x_axis.setPosition(sf::Vector2f(this->get_x(), this->get_y()));

    this->y_axis.setOrigin(sf::Vector2f(this->y_axis.getSize().x / 2, this->y_axis.getSize().y / 2));
    this->y_axis.setPosition(sf::Vector2f(this->get_x(), this->get_y()));

    // draw
    window.draw(this->x_axis);
    window.draw(this->y_axis);
}