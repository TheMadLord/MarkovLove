#include "gui.hpp"

gui::gui(sf::RenderWindow* window) {
    my_window = window;
}

gui::~gui() {

}

void gui::update(float deltaTime) {
    my_window->clear(sf::Color::Black);
    // code here

    my_window->display();
}
