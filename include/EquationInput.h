#pragma once
#include "constants.h"
#include "engine/Entity.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window.hpp>
#include <string>

class EquationInput : public Entity {
private:
    double height = 30;
    double x = 0;
    double y = SCREEN_HEIGHT - height;
    bool active = false;
    std::string current_input = "";
    std::string temp_input = "";
    sf::RectangleShape textbox;
    sf::Color color = sf::Color::Black;
    sf::Font font;
public:
    EquationInput();
    ~EquationInput();
    std::string get_input();
    std::string peek_input() { return this->current_input; };
    bool is_active() { return this->active; }
    void set_font(sf::Font& font) { this->font = font; }
    void step(sf::RenderWindow& window, sf::Event& event, bool poll);
    void render_after(sf::RenderWindow& window);
};
