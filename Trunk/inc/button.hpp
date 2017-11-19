#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class button {
public:
    button(std::string image_name, std::string b_name);
    button(std::string image_name);
    button();
    button(const button& b);
    button& operator=(const button& b);
    ~button();
    sf::Rect<int> getRect();
    sf::Sprite& getSprite();
    std::string getName();
protected:
    std::string name;
    std::string i_name;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Rect<int> rect;
};
