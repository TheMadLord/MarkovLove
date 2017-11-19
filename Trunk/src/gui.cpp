#include "gui.hpp"
#include <iostream>
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include <string>

gui::gui(sf::RenderWindow* window) {

    my_window = window;

    if (!my_font.loadFromFile("calibri.ttf")) { std::cout << "ERROR WITH LOADING FONT" << std::endl; }

    // initialize maps
    //girls - test
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

    //Virgo
    //Virgo_Enamored.png
    sf::Texture V_E;
    if (!V_E.loadFromFile("Virgo_Enamored.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    sf::Sprite V_E_s;
    V_E_s.setTexture(V_E);
    Virgo_sprites["Virgo_Enamored"] = V_E_s;
    sf::Texture V_A;
    if (!V_A.loadFromFile("Virgo_Angry.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    sf::Sprite V_A_s;
    V_A_s.setTexture(V_A);
    Virgo_sprites["Virgo_Angry"] = V_A_s;
    sf::Texture V_S;
    if (!V_S.loadFromFile("Virgo_Sad.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    sf::Sprite V_S_s;
    V_S_s.setTexture(V_S);
    Virgo_sprites["Virgo_Sad"] = V_S_s;
    sf::Texture V_H;
    if (!V_H.loadFromFile("Virgo_Enamored.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    sf::Sprite V_H_s;
    V_H_s.setTexture(V_H);
    Virgo_sprites["Virgo_Happy"] = V_H_s;

    // bkgs
    sf::Texture t;
    if(!t.loadFromFile("forrest_bkg.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    background_textures["forrest_texture"] = t;
    if(!t.loadFromFile("bakery_bkg.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    background_textures["bakery_texture"] = t;
    if(!t.loadFromFile("library_bkg.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    background_textures["library_texture"] = t;
    if(!t.loadFromFile("main_menu_bkg.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    background_textures["main_menu_texture"] = t;
    if(!t.loadFromFile("map_bkg.png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    background_textures["map_texture"] = t;
    sf::Sprite s;
    s.setTexture(background_textures["forrest_texture"]);
    background_sprites["forrest_bkg"] = s;
    s.setTexture(background_textures["bakery_texture"]);
    background_sprites["bakery_bkg"] = s;
    s.setTexture(background_textures["library_texture"]);
    background_sprites["library_bkg"] = s;
    s.setTexture(background_textures["main_menu_texture"]);
    background_sprites["main_menu_bkg"] = s;
    s.setTexture(background_textures["map_texture"]);
    background_sprites["map_bkg"] = s;

    // buttons
    buttons["main_menu_play"] = button("main_menu_play");
    buttons["main_menu_options"] = button("main_menu_options");
    buttons["overworld_forrest"] = button("overworld_forrest");
    buttons["overworld_menu"] = button("overworld_forrest");
    buttons["overworld_library"] = button("overworld_forrest");
    buttons["overworld_bakery"] = button("overworld_forrest");

    // button groups
    main_menu_buttons["play"] = &buttons["main_menu_play"];
    main_menu_buttons["play"]->getSprite().setPosition(200,100);
    main_menu_buttons["options"] = &buttons["main_menu_options"];
    main_menu_buttons["options"]->getSprite().setPosition(200,350);

    overworld_buttons["overworld_forrest"] = &buttons["overworld_forrest"];
    overworld_buttons["overworld_menu"] = &buttons["overworld_menu"];
    overworld_buttons["overworld_library"] = &buttons["overworld_library"];
    overworld_buttons["overworld_bakery"] = &buttons["overworld_bakery"];
    overworld_buttons["overworld_forrest"]->getSprite().setPosition(0,0);
    overworld_buttons["overworld_menu"]->getSprite().setPosition(0,300);
    overworld_buttons["overworld_library"]->getSprite().setPosition(400,0);
    overworld_buttons["overworld_bakery"]->getSprite().setPosition(400,300);
    overworld_buttons["overworld_forrest"]->getSprite().setColor(sf::Color(255, 255, 255, 0));
    overworld_buttons["overworld_menu"]->getSprite().setColor(sf::Color(255, 255, 255, 0));
    overworld_buttons["overworld_library"]->getSprite().setColor(sf::Color(255, 255, 255, 0));
    overworld_buttons["overworld_bakery"]->getSprite().setColor(sf::Color(255, 255, 255, 0));

    // set current-strings
    current_background = "main_menu_bkg";
    current_girl = "none";
    current_state = "menu";

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
        std::cout << "girl sprite \""+name+"\" not found" << std::endl;
        return sf::Sprite();
    } else {
        return iter->second;
    }
}

sf::Sprite gui::getBkg(std::string name){
    // find girl by string key
    std::map<std::string, sf::Sprite>::iterator iter = background_sprites.find(name);
    if (iter == background_sprites.end()){
        std::cout << "background image \""+name+"\" not found" << std::endl;
        return sf::Sprite();
    } else {
        return iter->second;
    }
}

sf::Sprite gui::getButton(std::string name){
    // UNDER CONSTRUCTION
    return sf::Sprite();
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
    //current_state = "overworld";
    //current_background = "forrest_spr";
}

void gui::button_function_main_menu_options(){
    my_window->close();
}

sf::RenderWindow* gui::my_window = nullptr;
