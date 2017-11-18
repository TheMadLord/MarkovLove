#include "gui.hpp"

gui::gui(sf::RenderWindow* window) {
    my_window = window;
    if (!font.loadFromFile("arial.ttf")) { /* error! */ }
    // initialize maps
    sf::Texture girl_1_u;
    if (!texture.loadFromFile("girl_1_u.png")) { /* error! */ }
    sf::Texture girl_1_h;
    if (!texture.loadFromFile("girl_1_u.png")) { /* error! */ }
    sf::Texture girl_1_s;
    if (!texture.loadFromFile("girl_1_u.png")) { /* error! */ }
    // put in map
    sf::Sprite sprite;
    sprite.setTexture(girl_1_h);
    // put in map
}

gui::~gui() {
    // delete arrays?
}

void gui::update(float deltaTime) {
    my_window->clear(sf::Color::Black);
    my_window.draw(sprite)

    my_window->display();
}
