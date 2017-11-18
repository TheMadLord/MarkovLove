#include "gui.hpp"
#include <iostream>

gui::gui(sf::RenderWindow* window) {
    my_window = window;
    if (!font.loadFromFile("arial.ttf")) { /* error! */ }
    // initialize maps
    sf::Texture girl_1_u;
    if (!girl_1_u.loadFromFile("girl_1_u.png")) { /* error! */ }
    sf::Texture girl_1_h;
    if (!girl_1_h.loadFromFile("girl_1_h.png")) { /* error! */ }
    sf::Texture girl_1_s;
    if (!girl_1_s.loadFromFile("girl_1_s.png")) { /* error! */ }
    girls_textures["girl_1_u"] = girl_1_u;
    girls_textures["girl_1_h"] = girl_1_h;
    girls_textures["girl_1_s"] = girl_1_s;
    sf::Sprite sprite;
    sprite.setTexture(girls_textures["girl_1_u"]);
    girls_sprites["girl_1_upset"] = sprite;
    sprite.setTexture(girls_textures["girl_1_h"]);
    girls_sprites["girl_1_happy"] = sprite;
    sprite.setTexture(girls_textures["girl_1_s"]);
    girls_sprites["girl_1_sad"] = sprite;
}

gui::~gui() {
    // delete maps ?
}

void gui::update(float deltaTime) {
    my_window->clear(sf::Color::Black);
    //my_window->draw(sprite);
    for (std::map<std::string, sf::Sprite>::iterator iter = girls_sprites.begin(); iter != girls_sprites.end(); iter++) {
        my_window->draw(iter->second);
        //std::cout << iter->first << std::endl; // prints name of thing getting drawn
    }
    my_window->display();
}
