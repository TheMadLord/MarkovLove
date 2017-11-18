#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include <string>

class gui {
public:
    gui(sf::RenderWindow* window);
    ~gui();
    void update(float deltaTime);
private:
    sf::RenderWindow* my_window;
    std::map<std::string,sf::Sprite> background_sprites;
    std::map<std::string,sf::Sprite> girls_sprites;
    std::map<std::string,sf::Sprite> button_sprites;
    sf::Font font;
};
