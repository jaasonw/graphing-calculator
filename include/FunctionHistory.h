#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include <memory>

#include "Function.h"
#include "constants.h"
#include "engine/Entity.h"

class FunctionHistory : public Entity {
   private:
    sf::CircleShape dot;
    std::shared_ptr<sf::Font> font;
    sf::Text text;
    std::string function_text;
    std::shared_ptr<Function> function;

   public:
    FunctionHistory();
    FunctionHistory(Function& function, sf::Font& font);
    void step(sf::RenderWindow& window, sf::Event& event, bool poll);
    void render_after(sf::RenderWindow& window);

    std::shared_ptr<Function> get_function() { return this->function; }
};
