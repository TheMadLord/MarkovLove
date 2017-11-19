
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include "button.hpp"

button::button(std::string image_name, std::string b_name){
    if(!texture.loadFromFile(image_name+".png")) { std::cout << "ERROR WITH LOADING 555 image" << std::endl; }
    sprite.setTexture(texture);
    i_name = image_name;
    name = b_name;
}

button::button(std::string image_name){
    if(!texture.loadFromFile(image_name+".png")) { std::cout << "ERROR WITH LOADING 7 image" << std::endl; }
    sprite.setTexture(texture);
    name = i_name = image_name;
}

button::button() {}

button::button(const button& b) {
    //std::cout << "copying " << b.name << std::endl;
    if(!texture.loadFromFile(b.i_name+".png")) { std::cout << "ERROR WITH LOADING 444 image" << std::endl; }
    sprite.setTexture(texture);
    i_name = b.name;
    name = b.name;
}

button& button::operator=(const button& b) {
    //std::cout << "copying " << b.name << std::endl;
    if(!texture.loadFromFile(b.i_name+".png")) { std::cout << "ERROR WITH LOADING image" << std::endl; }
    sprite.setTexture(texture);
    i_name = b.i_name;
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


