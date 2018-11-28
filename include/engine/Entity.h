#pragma once
#include <SFML/Graphics.hpp>

class Entity {
private:
    double screen_x;
    double screen_y;

public:
    Entity();
    virtual ~Entity();
    
    // runs every frame
    virtual void step();

    // runs every frame, reserved for drawing
    virtual void render(sf::RenderWindow& window);

    void set_x(int x) { screen_x = x; }
    void set_y(int y) { screen_y = y; }

    double get_x() { return screen_x; }
    double get_y() { return screen_y; }
};