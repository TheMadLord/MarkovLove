#include "gui.hpp"
#include <iostream>
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include <string>

gui::gui(sf::RenderWindow* window) {

    my_window = window;

    if (!my_font.loadFromFile("calibri.ttf")) { std::cout << "ERROR WITH LOADING FONT" << std::endl; }

    // initialize maps
    //girls
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

    // bkgs
    sf::Texture t;
    if(!t.loadFromFile("forrest_bkg.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    girls_textures["forrest_texture"] = t;
    if(!t.loadFromFile("bakery_bkg.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    girls_textures["bakery_texture"] = t;
    if(!t.loadFromFile("library_bkg.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    girls_textures["library_texture"] = t;
    if(!t.loadFromFile("main_menu_bkg.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    girls_textures["main_menu_texture"] = t;
    sf::Sprite s;
    s.setTexture(background_textures["forrest_texture"]);
    background_sprites["forrest_spr"] = s;
    s.setTexture(background_textures["bakery_texture"]);
    background_sprites["bakery_spr"] = s;
    s.setTexture(background_textures["library_texture"]);
    background_sprites["library_spr"] = s;
    s.setTexture(background_textures["main_menu_texture"]);
    background_sprites["main_menu_spr"] = s;

    // buttons
    buttons["main_menu_play"] = button("main_menu_play");
    buttons["main_menu_options"] = button("main_menu_options");
    button_functions["main_menu_play"] = button_function_main_menu_play;

    // implementation:
    // my_gui->button_functions[my_gui->buttons->name]();

    // button groups
    // ...

    // set current-strings
    current_background = "main_menu_spr";
    current_girl = "none";

    //initialize text_positions
    // onDATE (includes 10px matting)
    text_positions["option1"] = {30,430};
    text_positions["option2"] = {30,520};
    text_positions["girls_response"] = {70,200};

    //button_functions["button_1"] = my_static_function;
}

gui::~gui() {
    //delete background_textures; ?
}

void gui::update(float deltaTime) { // 2 - identifier, text to draw ?
    // CURRENTLY ONLY DRAWS HAPPY GIRL TO SCREEN

    //my_window->draw(sprite);
    /*
    for (std::map<std::string, sf::Sprite>::iterator iter = girls_sprites.begin(); iter != girls_sprites.end(); iter++) {
        my_window->draw(iter->second);
        //std::cout << iter->first << std::endl; // prints name of thing getting drawn
    }
    */
    my_window->draw(girls_sprites.begin()->second);

}

sf::Sprite gui::getGirl(std::string name){
    // find girl by string key
    if (name == "none") { return sf::Sprite(); }
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
    // UNDER CONSTRUCTION
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

void gui::button_function_main_menu_play(){

}

void gui::button_function_main_menu_options(){

}
