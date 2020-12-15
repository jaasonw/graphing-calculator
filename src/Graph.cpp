#include "Graph.h"

Graph::Graph() : Entity() {
    // load font
    SourceCodePro.loadFromFile("SourceCodePro-Regular.ttf");

    // load font into text input
    equation_input.set_font(SourceCodePro);

    // set position
    set_x(SCREEN_WIDTH / 2);
    set_y(SCREEN_HEIGHT / 2);

    // create axis
    x_axis =
        sf::RectangleShape(sf::Vector2f(SCREEN_WIDTH * 1000, LINE_THICKNESS));
    y_axis =
        sf::RectangleShape(sf::Vector2f(LINE_THICKNESS, SCREEN_HEIGHT * 1000));

    // color axis
    x_axis.setFillColor(AXIS_COLOR);
    y_axis.setFillColor(AXIS_COLOR);

    // initialize drag stuff
    dragpos1 = sf::Vector2i(0, 0);
    dragpos2 = sf::Vector2i(0, 0);
}

void Graph::step(sf::RenderWindow& window, sf::Event& event, bool poll) {
    // event handling stuff
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!dragging) {
            dragging = true;
            dragpos1 = sf::Mouse::getPosition(window);
            dragpos2 = sf::Mouse::getPosition(window);
        } else if (dragging) {
            dragpos1 = dragpos2;
            dragpos2 = sf::Mouse::getPosition(window);
            set_x(get_x() + dragpos2.x - dragpos1.x);
            set_y(get_y() + dragpos2.y - dragpos1.y);
        }
    } else {
        dragging = false;
    }
    if (poll) {
        // mouse wheel zooming
        if (event.type == sf::Event::MouseWheelScrolled) {
            if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                if (zoom +
                        ZOOM_INCREMENT * (event.mouseWheelScroll.delta / 10) >
                    10)
                    zoom +=
                        ZOOM_INCREMENT * (event.mouseWheelScroll.delta / 10);
            }
        }
        if (event.type == sf::Event::KeyPressed &&
            !equation_input.is_active()) {
            // zooming
            if (event.key.code == sf::Keyboard::RBracket) {
                zoom += ZOOM_INCREMENT;
            } else if (event.key.code == sf::Keyboard::LBracket) {
                if (zoom > 10) zoom -= ZOOM_INCREMENT;
            }

            // panning
            if (event.key.code == sf::Keyboard::Left) {
                set_x(get_x() + PAN_INCREMENT);
            } else if (event.key.code == sf::Keyboard::Right) {
                set_x(get_x() - PAN_INCREMENT);
            } else if (event.key.code == sf::Keyboard::Up) {
                set_y(get_y() + PAN_INCREMENT);
            } else if (event.key.code == sf::Keyboard::Down) {
                set_y(get_y() - PAN_INCREMENT);
            }

            // reset view
            if (event.key.code == sf::Keyboard::R) {
                set_x(SCREEN_WIDTH / 2);
                set_y(SCREEN_HEIGHT / 2);
                zoom = GRAPH_DEFAULT_ZOOM;
            }
        }
    }

    if (equation_input.peek_input() != "") {
        auto eq = equation_input.get_input();
        plot_expression(eq);
    }
}

void Graph::plot_expression(std::string expression, double low, double high) {
    std::cout << "plotting: " << expression << std::endl;
    std::shared_ptr<Function> func;
    try {
        func = std::make_shared<Function>(expression);
    } catch (...) {
        std::cout << "error parsing function: " << expression << std::endl;
        return;
    }
    func->set_bounds(low, high);
    functions.push_back(func);
    function_history.push_back(std::shared_ptr<FunctionHistory>(
        new FunctionHistory(*func, this->SourceCodePro)));
}

void Graph::render(sf::RenderWindow& window) {
    // set positions
    x_axis.setOrigin(
        sf::Vector2f(x_axis.getSize().x / 2, x_axis.getSize().y / 2));
    x_axis.setPosition(sf::Vector2f(get_x(), get_y()));

    y_axis.setOrigin(
        sf::Vector2f(y_axis.getSize().x / 2, y_axis.getSize().y / 2));
    y_axis.setPosition(sf::Vector2f(get_x(), get_y()));

    // draw functions
    for (auto function : functions) {
        function->plot(get_x(), get_y(), zoom);
    }

    // draw axis
    window.draw(x_axis);
    window.draw(y_axis);
}

void Graph::render_after(sf::RenderWindow& window) {
    // draw controls text
    sf::Text controls;
    controls.setFont(SourceCodePro);
    controls.setCharacterSize(20);
    controls.setString(
        "Arrow keys: pan\n]: Zoom in\n[: Zoom out\nR: Reset view");
    window.draw(controls);

    // draw functions list
    for (int i = 0; i < function_history.size(); i++) {
        function_history.at(i)->set_x(SCREEN_WIDTH - 180);
        function_history.at(i)->set_y((i * 25));
    }
}