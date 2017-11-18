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
    typedef std::function<void(gui)> button_function;
    sf::RenderWindow* my_window;
    std::string current_background;
    std::string current_girl;
    std::map<std::string, sf::Rect<int>> on_date_buttons;
    std::map<std::string, sf::Rect<int>> main_menu_buttons;
    std::map<std::string, sf::Rect<int>> overworld_buttons;
    gui(sf::RenderWindow* window);
    ~gui();
    void update(float deltaTime);
    sf::Sprite getGirl(std::string name);
    sf::Sprite getBkg(std::string name);
    sf::Sprite getButton(std::string name);
    void drawText(std::string text, std::vector<int> location);
    void display_Markov() {}
private:
    sf::Font my_font;
    static void my_static_function(gui* g);
    std::map<std::string,std::vector<int>> text_positions;
    std::map<std::string,sf::Texture> background_textures;
    std::map<std::string,sf::Sprite> background_sprites;
    std::map<std::string,sf::Texture> girls_textures;
    std::map<std::string,sf::Sprite> girls_sprites;
    std::map<std::string,button> buttons;
    std::map<std::string,button_function> button_functions;
    //std::map<std::string,button_child> buttons;
};
