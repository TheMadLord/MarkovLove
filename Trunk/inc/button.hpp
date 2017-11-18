#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class button {
public:
    button(std::string);
    button();
    ~button();
    sf::Rect<int> getRect();
    sf::Sprite getSprite();
    std::vector<int> getPos();
    void take_effect();
private:
    std::string name;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Rect<int> rect;
    std::vector<int> position;
};
