#include "Graph.h"

Graph::Graph() : Entity() {
    this->set_x(SCREEN_HEIGHT / 2);
    this->set_y(SCREEN_WIDTH / 2);
    
    this->x_axis = sf::RectangleShape(sf::Vector2f(SCREEN_HEIGHT, LINE_THICKNESS));
    this->y_axis = sf::RectangleShape(sf::Vector2f(LINE_THICKNESS, SCREEN_WIDTH));

    this->x_axis.setFillColor(AXIS_COLOR);
    this->y_axis.setFillColor(AXIS_COLOR);

    // functions
    this->functions.push_back(new Function());
}

void Graph::render(sf::RenderWindow& window) {
    // set positions
    this->x_axis.setOrigin(sf::Vector2f(this->x_axis.getSize().x / 2, this->x_axis.getSize().y / 2));
    this->x_axis.setPosition(sf::Vector2f(this->get_x(), this->get_y()));

    this->y_axis.setOrigin(sf::Vector2f(this->y_axis.getSize().x / 2, this->y_axis.getSize().y / 2));
    this->y_axis.setPosition(sf::Vector2f(this->get_x(), this->get_y()));

    // draw functions
    for (auto function : functions) {
        function->plot(this->get_x(), this->get_y(), ZOOM_TO_PIXEL_SCALE);
    }

    // draw axis
    window.draw(this->x_axis);
    window.draw(this->y_axis);
}