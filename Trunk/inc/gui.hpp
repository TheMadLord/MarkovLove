#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class gui {
public:
    gui(sf::RenderWindow* window);
    ~gui();
    void update(float deltaTime);
private:
    sf::RenderWindow* my_window;
};
