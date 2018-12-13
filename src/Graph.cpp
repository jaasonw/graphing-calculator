#include "Graph.h"

Graph::Graph() : Entity() {
    // load font
    this->SourceCodePro.loadFromFile("SourceCodePro-Regular.ttf");

    // load font into text input
    equation_input.set_font(this->SourceCodePro);

    // set position
    this->set_x(SCREEN_WIDTH / 2);
    this->set_y(SCREEN_HEIGHT / 2);
    
    // create axis
    this->x_axis = sf::RectangleShape(sf::Vector2f(SCREEN_WIDTH * 1000, LINE_THICKNESS));
    this->y_axis = sf::RectangleShape(sf::Vector2f(LINE_THICKNESS, SCREEN_HEIGHT * 1000));

    // color axis
    this->x_axis.setFillColor(AXIS_COLOR);
    this->y_axis.setFillColor(AXIS_COLOR);

    // functions
    // this->plot_expression("5x");
    // this->plot_expression("3x + 2");
    // this->plot_expression("1/x");
    // this->plot_expression("tan(x)");
}

void Graph::step(sf::RenderWindow& window, sf::Event& event, bool poll) {
    // event handling stuff
    if (poll) {
        // mouse wheel zooming
        if (event.type == sf::Event::MouseWheelScrolled) {
            if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                this->zoom += ZOOM_INCREMENT * (event.mouseWheelScroll.delta / 10);
            }
        }
        if (event.type == sf::Event::KeyPressed && !this->equation_input.is_active()) {
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
                this->set_x(this->get_x() - PAN_INCREMENT);
            }
            else if (event.key.code == sf::Keyboard::Right) {
                this->set_x(this->get_x() + PAN_INCREMENT);
            }
            else if (event.key.code == sf::Keyboard::Up) {
                this->set_y(this->get_y() - PAN_INCREMENT);
            }
            else if (event.key.code == sf::Keyboard::Down) {
                this->set_y(this->get_y() + PAN_INCREMENT);
            }

            // reset view
            if (event.key.code == sf::Keyboard::R) {
                this->set_x(SCREEN_WIDTH / 2);
                this->set_y(SCREEN_HEIGHT / 2);
                this->zoom = GRAPH_DEFAULT_ZOOM;
            }
        }
    }

    if (equation_input.peek_input() != "") {
        auto eq = equation_input.get_input();
        this->plot_expression(eq);
    }
}

void Graph::plot_expression(std::string expression, double low, double high) {
    std::cout << "plotting: " << expression << std::endl;
    Function* func;
    try {
        func = new Function(expression);
    }
    catch(...) {
        std::cout << "error parsing function: " << expression << std::endl;
        return;
    }
    func->set_bounds(low, high);
    this->functions.push_back(func);
}

void Graph::render(sf::RenderWindow& window) {
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

void Graph::render_after(sf::RenderWindow& window) {
    // draw controls text
    sf::Text controls;
    controls.setFont(this->SourceCodePro);
    controls.setCharacterSize(15);
    controls.setString("Arrow keys: pan\n]: Zoom in\n[: Zoom out\nR: Reset view");
    window.draw(controls);

    // draw functions list
    for (int i = 0; i < this->functions.size(); i++) {
        sf::CircleShape dot;
        sf::Text function_text;
        function_text.setFont(this->SourceCodePro);
        function_text.setCharacterSize(15);
        function_text.setString(this->functions.at(i)->get_string());
        function_text.setPosition(SCREEN_WIDTH - 180, 15 + (i * 15));
        dot.setRadius(5);
        dot.setFillColor(this->functions.at(i)->get_color());
        dot.setPosition(SCREEN_WIDTH - 200, 20 + (i * 15));
        window.draw(function_text);
        window.draw(dot);
    }
}