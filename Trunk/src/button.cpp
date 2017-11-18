
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <vector>

button::button(string image_name){
    sf::Texture texture;
    if(!texture.loadFromFile(image_name)) { std::cout << "ERROR WITH LOADING image" << std::endl; }

    sf::Sprite sprite;
    sprite.setTexture(texture);
}

button::~button(){
    // delete shit, i suppose
}

sf::Rect button::getRect(){
    return rect;
}

sf::Sprite button::getSprite(){
    return sprite;
}

std::vector<int> button::getPos(){
    return position;
}

void button::take_effect(){
    // do whatever the button does ...
    // might need gui?
}

void button_x::take_effect(){

}
