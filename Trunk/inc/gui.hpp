#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <map>
#include <string>
#include <vector>
#include <functional>
#include "button.hpp"

class gui {
public:
    typedef std::function<void()> button_function;
    static sf::RenderWindow* my_window;
    std::string current_background;
    std::string current_girl;
    std::string current_state; // "menu", "date", "overworld"
    std::map<std::string, button*> date_buttons;
    std::map<std::string, button*> main_menu_buttons;
    std::map<std::string, button*> overworld_buttons;
    std::map<std::string,button_function> button_functions;
    std::map<std::string, std::string> emotions;
    gui(sf::RenderWindow* window);
    ~gui();
    void update(float deltaTime);
    sf::Sprite getBkg(std::string name);
    sf::Sprite getButton(std::string name);
    void drawText(std::string text, std::vector<int> location);
    void display_Markov() {} // eventually ...
    void drawMenu();

    static void button_function_main_menu_play();
    static void button_function_main_menu_options();

    std::map<std::string,sf::Sprite> Virgo_sprites;
    std::map<std::string,sf::Texture> Virgo_textures;

    std::vector<std::vector<int>> text_positions;

private:
    sf::Font my_font;
    static void my_static_function(gui* g);
    std::map<std::string,sf::Texture> background_textures;
    std::map<std::string,sf::Sprite> background_sprites;
    std::map<std::string,button> buttons;
};
