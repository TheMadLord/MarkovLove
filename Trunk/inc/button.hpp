#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Button {
public:
    Button();
    ~Button();
    sf::Rect getRect();
    sf::Sprite getSprite();
    std::vector<int> getPos();
    void take_effect();
private:
    std::string name;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Rect rect;
    std::vector<int> position;
};
