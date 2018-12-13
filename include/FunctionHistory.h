#pragma once
#include "Function.h"
#include "constants.h"
#include "engine/Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

class FunctionHistory : public Entity {
private:
    sf::CircleShape dot;
    sf::Font font;
    sf::Text text;
    std::string function_text;
    Function* function;

public:
    FunctionHistory();
    FunctionHistory(Function* function, sf::Font& font);
    void step(sf::RenderWindow& window, sf::Event& event, bool poll);
    void render_after(sf::RenderWindow& window);

    Function* get_function() { return this->function; }
};
