#include "EquationInput.h"
#include <iostream>

EquationInput::EquationInput() : Entity() {
    this->set_visible(this->active);
    this->color.a = 100;
    this->textbox.setPosition(x, y);
    this->textbox.setSize(sf::Vector2f(SCREEN_WIDTH, this->height));
    this->textbox.setFillColor(color);
}
EquationInput::~EquationInput() {}

void EquationInput::step(sf::RenderWindow& window, sf::Event& event) {
    // TODO CLEAN UP THIS REALLY BAD EVENT HANDLING HACK CUS I GOOF'D
    if (event.type == sf::Event::KeyPressed) {
        // std::cout << "enter pressed" << std::endl;
        if (event.key.code == sf::Keyboard::Enter) {
            if (!this->active) {
                current_input = "";
            }
            else {
                current_input = temp_input;
                temp_input = "";
            }
            this->active = !this->active;
            this->set_visible(this->active);
        }
    }
    if (window.pollEvent(event)) {
        if (event.type == sf::Event::TextEntered) {
            if (this->active) {
                if (event.text.unicode == '\b' && this->temp_input.size() > 0)
                    this->temp_input.erase(this->temp_input.size() - 1, 1);
                else if (event.text.unicode < 128) {
                    this->temp_input += static_cast<char>(event.text.unicode);
                }
            }
        }
    }
}

std::string EquationInput::get_input() {
    std::string hold = this->current_input;
    this->current_input = "";
    return hold;
}

void EquationInput::render_after(sf::RenderWindow& window) {
    sf::Text input;
    input.setFont(this->font);
    input.setCharacterSize(20);
    input.setString(temp_input);
    input.setPosition(x, y + this->height / 2);
    window.draw(input);
    window.draw(this->textbox);
}