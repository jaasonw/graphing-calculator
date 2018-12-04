#include "Graph.h"

Graph::Graph() : Entity() {
    // load font
    this->SourceCodePro.loadFromFile("SourceCodePro-Regular.ttf");

    // set position
    this->set_x(SCREEN_HEIGHT / 2);
    this->set_y(SCREEN_WIDTH / 2);
    
    // create axis
    this->x_axis = sf::RectangleShape(sf::Vector2f(SCREEN_HEIGHT * 1000, LINE_THICKNESS));
    this->y_axis = sf::RectangleShape(sf::Vector2f(LINE_THICKNESS, SCREEN_WIDTH * 1000));

    // color axis
    this->x_axis.setFillColor(AXIS_COLOR);
    this->y_axis.setFillColor(AXIS_COLOR);

    // functions
    this->functions.push_back(new Function());
}

void Graph::step(sf::RenderWindow& window, const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        // zooming
        if (event.key.code == sf::Keyboard::RBracket) {
            this->zoom += ZOOM_INCREMENT;
        }
        else if (event.key.code == sf::Keyboard::LBracket) {
            if (zoom > 10)
                this->zoom -= ZOOM_INCREMENT;
        }

        // panning
        if (event.key.code == sf::Keyboard::Left) {
            this->set_x(this->get_x() + PAN_INCREMENT);
        }
        else if (event.key.code == sf::Keyboard::Right) {
            this->set_x(this->get_x() - PAN_INCREMENT);
        }
        else if (event.key.code == sf::Keyboard::Up) {
            this->set_y(this->get_y() + PAN_INCREMENT);
        }
        else if (event.key.code == sf::Keyboard::Down) {
            this->set_y(this->get_y() - PAN_INCREMENT);
        }

        // reset view
        if (event.key.code == sf::Keyboard::R) {
            this->set_x(SCREEN_HEIGHT / 2);
            this->set_y(SCREEN_WIDTH / 2);
            this->zoom = GRAPH_DEFAULT_ZOOM;
        }
    }
}

void Graph::render(sf::RenderWindow& window) {
    // draw controls text
    sf::Text controls;
    controls.setFont(this->SourceCodePro);
    controls.setCharacterSize(15);
    controls.setString("Arrow keys: pan\n]: Zoom in\n[: Zoom out\nR: Reset view");
    window.draw(controls);

    // set positions
    this->x_axis.setOrigin(sf::Vector2f(this->x_axis.getSize().x / 2, this->x_axis.getSize().y / 2));
    this->x_axis.setPosition(sf::Vector2f(this->get_x(), this->get_y()));

    this->y_axis.setOrigin(sf::Vector2f(this->y_axis.getSize().x / 2, this->y_axis.getSize().y / 2));
    this->y_axis.setPosition(sf::Vector2f(this->get_x(), this->get_y()));

    // draw functions
    for (auto function : functions) {
        function->plot(this->get_x(), this->get_y(), this->zoom);
    }

    // draw axis
    window.draw(this->x_axis);
    window.draw(this->y_axis);
}