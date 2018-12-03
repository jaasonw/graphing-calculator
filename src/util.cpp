#include "util.h"

sf::VertexArray create_line_thickness(double x1, double y1, double x2, double y2, double thickness, sf::Color color) {
    sf::VertexArray line(sf::TrianglesStrip, 4);
    line[0] = sf::Vector2f(x1 + (thickness / 2), y1 - (thickness / 2));
    line[1] = sf::Vector2f(x1 + (thickness / 2), y1 + (thickness / 2));
    line[2] = sf::Vector2f(x2 + (thickness / 2), y2 - (thickness / 2));
    line[3] = sf::Vector2f(x2 + (thickness / 2), y2 + (thickness / 2));
    for(int i = 0; i <= 3; i++) {
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