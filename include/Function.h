#pragma once
#include "engine/Entity.h"
#include "rpn/rpn.h"

class Function : public Entity {
private:
    Queue<Token*> postfix;
public:
    Function(/* args */);
    ~Function();
    void step();
    void render(sf::RenderWindow& window);
};

Function::Function(/* args */) {}
Function::~Function() {}
void Function::step() {}
void Function::render(sf::RenderWindow& window) {}
