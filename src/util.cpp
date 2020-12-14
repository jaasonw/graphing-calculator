#include "util.h"

sf::VertexArray create_line(double x1, double y1, double x2, double y2,
                            const sf::Color& color) {
    sf::VertexArray line(sf::LinesStrip, 2);
    // totally not scuffed asymtote detection
    if ((((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))) > 640000) {
        line[0] = sf::Vector2f(x2, y2);
        line[1] = sf::Vector2f(x2, y2);
    } else {
        line[0] = sf::Vector2f(x1, y1);
        line[1] = sf::Vector2f(x2, y2);
    }
    for (int i = 0; i < 2; i++) {
        line[i].color = color;
    }
    return line;
}