#pragma once
#include "engine/Entity.h"

class Point : public Entity {
private:
    double graph_x;
    double graph_y;
    const double RADIUS = 1;
    sf::Color color = sf::Color::Red;
    sf::CircleShape point;

public:
    Point();
    Point(double graph_x, double graph_y);
    ~Point();
    void step(sf::RenderWindow& window, const sf::Event& event);
    void render(sf::RenderWindow& window);

    void plot(double screen_x, double screen_y);
    void setColor(sf::Color color) { this->color = color; }
    
    double get_graph_x() { return graph_x; }
    double get_graph_y() { return graph_y; }

    void set_graph_x(double graph_x) { this->graph_x = graph_x; }
    void set_graph_y(double graph_y) { this->graph_y = graph_y; }

    sf::Color get_color(sf::Color color) { return this->color; }
    void set_color(sf::Color color) { this->color = color; }
};
