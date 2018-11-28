#include "Graph.h"
#include "constants.h"

Graph::Graph() {
    this->set_x(SCREEN_WIDTH / 2);
    this->set_y(SCREEN_HEIGHT / 2);
    
    this->x_axis = sf::RectangleShape(sf::Vector2f(SCREEN_HEIGHT, LINE_THICKNESS));
    this->y_axis = sf::RectangleShape(sf::Vector2f(LINE_THICKNESS, SCREEN_HEIGHT));

    this->x_axis.setFillColor(sf::Color::Green);
    this->y_axis.setFillColor(sf::Color::Green);
}

void Graph::render(sf::RenderWindow& window) {
    // set positions
    this->x_axis.setPosition(sf::Vector2f(0, this->get_y()));
    this->y_axis.setPosition(sf::Vector2f(this->get_x(), 0));
    // draw
    window.draw(this->x_axis);
    window.draw(this->y_axis);
}