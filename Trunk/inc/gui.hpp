#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <map>
#include <string>
#include <vector>

class gui {
public:
    gui(sf::RenderWindow* window);
    ~gui();
    void update(float deltaTime, bool);
    sf::Sprite getGirl(std::string name);
    sf::Sprite getBkg(std::string name);
    sf::Sprite getButton(std::string name);
    void drawText(std::string text, std::vector<int> location);
    void display_Markov() {};
private:
    sf::RenderWindow* my_window;
    std::map<std::string,sf::Texture> background_textures;
    std::map<std::string,sf::Sprite> background_sprites;
    std::map<std::string,sf::Texture> girls_textures;
    std::map<std::string,sf::Sprite> girls_sprites;
    std::map<std::string,sf::Texture> button_textures;
    std::map<std::string,sf::Sprite> button_sprites;
    sf::Font my_font;
};
