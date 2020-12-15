#include "Function.h"

#include "engine/Engine.h"

Function::Function() : Entity() {
    // example test function
    function_string = "sin(x)";
    postfix = infix_to_postfix(tokenize(function_string));
    // for (auto it = postfix.b; it != postfix.back(); it++) {
    //     std::cout << **it << std::endl;
    // }
    update_graph();

    color.r = rand() % 255;
    color.g = rand() % 255;
    color.b = rand() % 255;
}

Function::Function(std::string function_string)
    : Entity(), function_string(function_string) {
    color.r = rand() % 255;
    color.g = rand() % 255;
    color.b = rand() % 255;
    try {
        postfix = infix_to_postfix(tokenize(function_string));
    } catch (...) {
        std::cout << "error parsing function: " << function_string << std::endl;
        return;
    }
    update_graph();
}

// Function::~Function() {
//     while (!postfix.empty()) {
//         delete postfix.pop();
//     }
// }

void Function::step(sf::RenderWindow& window, sf::Event& event, bool poll) {
    // TODO: maybe change this so it plots a point every frame instead
    // of the constructor
}

void Function::render(sf::RenderWindow& window) {
    // do translating to screen coords here
    for (unsigned int i = 0; i < points.size(); i++) {
        if (i != 0) {
            double x1 = (points[i].x * zoom) + origin_x;
            double y1 = -((points[i].y * zoom)) + origin_y;
            double x2 = (points[i - 1].x * zoom) + origin_x;
            double y2 = -((points[i - 1].y * zoom)) + origin_y;
            if ((x1 <= window.getSize().x + window.getSize().x / 4 && x1 >= 0 &&
                y1 <= window.getSize().y + window.getSize().y / 4 && y1 >= 0) ||
                (x2 <= window.getSize().x + window.getSize().x / 4 && x2 >= 0 &&
                y2 <= window.getSize().y + window.getSize().y / 4 && y2 >= 0)) {
                window.draw(create_line(x1, y1, x2, y2, color));
            }
        }
    }
}

void Function::plot(double screen_x, double screen_y, double zoom) {
    this->zoom = zoom;
    this->origin_x = screen_x;
    this->origin_y = screen_y;
}

void Function::update_graph() {
    for (double i = interval_start; i < interval_end; i += point_frequency) {
        try {
            points.push_back(sf::Vector2f(i, eval(postfix, i)));
        } catch (...) {
            std::cout << "something went wrong here, maybe an asymtote, maybe "
                         "an invalid expression"
                      << std::endl;
        }
    }
}

void Function::set_bounds(double low, double high) {
    if (low > high) {
        interval_start = high;
        interval_end = low;
    } else {
        interval_start = low;
        interval_end = high;
    }
    update_graph();
}