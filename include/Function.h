#pragma once
#include "Point.h"
#include "engine/Entity.h"
#include "rpn/rpn.h"
#include <vector>

class Function : public Entity {
private:
    double interval_start;
    double interval_end;
    double point_frequency;
    // the screen x and y of the origin
    double origin_x;
    double origin_y;
    double zoom;

    Queue<Token*> postfix;
    std::vector<Point*> points;
public:
    Function();
    ~Function();
    void step();
    void render(sf::RenderWindow& window);

    // pass in the screen coordinates of the graph origin
    void plot(double screen_x, double screen_y, double zoom);
};