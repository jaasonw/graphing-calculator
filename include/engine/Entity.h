#pragma once
#include <SFML/Graphics.hpp>

class Entity {
   private:
    bool visible = true;
    double screen_x;
    double screen_y;
    int layer = 0;

   public:
    Entity();
    virtual ~Entity();

    // runs every frame
    virtual void step(sf::RenderWindow& window, sf::Event& event, bool poll);

    // runs every frame, reserved for drawing
    virtual void render(sf::RenderWindow& window);

    // really bad way of doing this but time is scarce
    // reserved for things that need to be drawn at the top (huds, overlays,
    // etc)
    virtual void render_after(sf::RenderWindow& window);

    void set_x(int x) { screen_x = x; }
    void set_y(int y) { screen_y = y; }

    double get_x() { return screen_x; }
    double get_y() { return screen_y; }

    bool is_visible() { return visible; }
    bool toggle_visible() { return visible = !visible; }
    void set_visible(bool visible) { this->visible = visible; }
};
