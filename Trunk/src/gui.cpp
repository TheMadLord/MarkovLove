#include "gui.hpp"
#include <iostream>
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include <string>

gui::gui(sf::RenderWindow* window) {

    my_window = window;

    if (!my_font.loadFromFile("calibri.ttf")) { std::cout << "ERROR WITH LOADING FONT" << std::endl; }

    // initialize maps
    sf::Texture girl_1_u;
    if (!girl_1_u.loadFromFile("girl_1_u.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    sf::Texture girl_1_h;
    if (!girl_1_h.loadFromFile("girl_1_h.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    sf::Texture girl_1_s;
    if (!girl_1_s.loadFromFile("girl_1_s.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
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

    //initialize text_positions
    // onDATE (includes 10px matting)
    // option 1: (30,430)
    // option 2: (30, 520)
    // girl's response: (70, 200)
    text_positions["option1"] = {30,430};
    text_positions["option2"] = {30,520};
    text_positions["girls_response"] = {70,200};

}

gui::~gui() {
    // delete maps ?
}

void gui::update(float deltaTime, bool onDate, std::map<std::string, std::string> current_text) { // 2 - identifier, text to draw ?
    // CURRENTLY ONLY DRAWS HAPPY GIRL TO SCREEN
    my_window->clear(sf::Color::Black);

    // ALL DRAW CODE GOES HERE
    if (onDate){
        // draw girl and text in on-date format
    } else {
        // draw things as if you're not on a date with a girl
        // this includes scenarios where you're visiting a shop or something on your own
    }

    //my_window->draw(sprite);
    /*
    for (std::map<std::string, sf::Sprite>::iterator iter = girls_sprites.begin(); iter != girls_sprites.end(); iter++) {
        my_window->draw(iter->second);
        //std::cout << iter->first << std::endl; // prints name of thing getting drawn
    }
    */
    my_window->draw(girls_sprites.begin()->second);
    my_window->display();
}

sf::Sprite gui::getGirl(std::string name){
    // find girl by string key
    std::map<std::string, sf::Sprite>::iterator iter = girls_sprites.find(name);
    if (iter == girls_sprites.end()){
        std::cout << "girl sprite not found" << std::endl;
        return sf::Sprite();
    } else {
        return iter->second;
    }
}

sf::Sprite gui::getBkg(std::string name){
    // find girl by string key
    std::map<std::string, sf::Sprite>::iterator iter = background_sprites.find(name);
    if (iter == background_sprites.end()){
        std::cout << "background image not found" << std::endl;
        return sf::Sprite();
    } else {
        return iter->second;
    }
}

sf::Sprite gui::getButton(std::string name){
    // find girl by string key
    std::map<std::string, sf::Sprite>::iterator iter = button_sprites.find(name);
    if (iter == button_sprites.end()){
        std::cout << "button sprite not found" << std::endl;
        return sf::Sprite();
    } else {
        return iter->second;
    }
}

void gui::drawText(std::string text, std::vector<int> location){
    // THIS FUNCTION NEEDS TO BE CALLED IN GUI UPDATE
    sf::Text my_text_object;
    my_text_object.setFont(my_font);

    my_text_object.setString(text);
    my_text_object.setCharacterSize(24); // in pixels, not points!
    my_text_object.setFillColor(sf::Color::Black);
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined); THIS MAKES TEXT BOLD AND UNDERLINED
    my_window->draw(my_text_object);
}
