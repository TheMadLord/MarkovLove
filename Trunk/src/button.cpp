
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <vector>

Button(){

}

~Button(){

}

sf::Rect getRect(){
    return rect;
}

sf::Sprite getSprite(){
    return sprite;
}

std::vector<int> getPos(){
    return position;
}

void take_effect(){
    // do whatever the button does
    // might need gui?
}
