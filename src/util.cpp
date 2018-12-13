#include "util.h"

sf::VertexArray create_line(double x1, double y1, double x2, double y2, sf::Color color) {
    sf::VertexArray line(sf::LinesStrip, 2);
    // totally not scuffed asymtote detection
    if ((((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))) > 640000) {
        line[0] = sf::Vector2f(x2, y2);
        line[1] = sf::Vector2f(x2, y2);
    }
    else {
        line[0] = sf::Vector2f(x1, y1);
        line[1] = sf::Vector2f(x2, y2);
    }
    for(int i = 0; i < 2; i++) {
        line[i].color = color;
    }
    return line;
}

// sf::RectangleShape create_line_thickness(double x1, double y1, double x2, double y2, double thickness, sf::Color color) {
//     // double distance = sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
//     // sf::RectangleShape line(sf::Vector2f(thickness, distance));
//     // line.setPosition(sf::Vector2f(x1, y1));
//     // line.setOrigin(sf::Vector2f(0, thickness / 2));
//     // // line.rotate(-45);
//     // // line.rotate(-atan(y2 / x2) * (180.0 / 3.141592653589793238463));
//     // return line;
// }