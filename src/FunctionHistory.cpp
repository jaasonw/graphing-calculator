#include "FunctionHistory.h"

FunctionHistory::FunctionHistory() : Entity() {}

FunctionHistory::FunctionHistory(Function* function, sf::Font& font)
    : function(function), font(font) {}


void FunctionHistory::step(sf::RenderWindow& window, sf::Event& event, bool poll) {
    if (poll) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(mousePos.x, mousePos.y);
                if (this->dot.getGlobalBounds().contains(mousePosF)) {
                    this->function->toggle_visible();
                }
            }
        }
    }
}

void FunctionHistory::render_after(sf::RenderWindow& window) {
    this->text.setFont(this->font);
    this->text.setCharacterSize(20);
    this->text.setString(this->function->get_string());
    this->text.setPosition(this->get_x(), this->get_y());

    this->dot.setRadius(7);
    sf::Color color = this->function->get_color();
    if (!this->function->is_visible()) {
        color.a = 100;
    }
    this->dot.setFillColor(color);
    this->dot.setPosition(this->get_x() - 20, this->get_y() + 7);

    window.draw(this->text);
    window.draw(this->dot);
}