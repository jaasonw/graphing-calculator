#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <list>
#include <memory>

#include "Entity.h"
#include "constants.h"

class Engine {
   private:
    static std::list<std::shared_ptr<Entity>> entities;
    static sf::Font SourceCodePro;
    sf::RenderWindow window;

   public:
    Engine();
    void run();
    void stop();
    static std::shared_ptr<Entity> add_entity(std::shared_ptr<Entity> entity);
    static void remove_entity(std::shared_ptr<Entity> entity);
};
