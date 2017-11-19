
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include "button.hpp"

button::button(std::string image_name){
    if(!texture.loadFromFile(image_name+".png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    sprite.setTexture(texture);
    name = image_name;
}

button::button() {}

button::button(const button& b) {
    //std::cout << "copying " << b.name << std::endl;
    if(!texture.loadFromFile(b.name+".png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    sprite.setTexture(texture);
    name = b.name;
}

button& button::operator=(const button& b) {
    //std::cout << "copying " << b.name << std::endl;
    if(!texture.loadFromFile(b.name+".png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    sprite.setTexture(texture);
    name = b.name;
    return *this;
}

button::~button(){
    // delete shit, i suppose
}

sf::Rect<int> button::getRect(){
    rect = sf::Rect<int>(sprite.getGlobalBounds());
    return rect;
}

sf::Sprite& button::getSprite(){
    return sprite;
}

std::string button::getName(){
    return name;
}


