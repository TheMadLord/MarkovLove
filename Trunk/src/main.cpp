// reading a text file
#include <iostream>
#include <fstream>
#include <string>

#include "parser.hpp"
#include "gui.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>

using namespace std;

int main () {
	parseFile("L1.txt");
	float deltaTime;
	sf::Clock clock;
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "MarkovLove");
    gui* my_gui = new gui(window);

    // START OF GAME LOOP
    while (window->isOpen()) {
        // INPUTS
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window->close();
            }
        }

        // UPDATE
        deltaTime = clock.restart().asSeconds();
        my_gui->update(deltaTime);

        // RENDER
        my_gui->update(deltaTime);
    }
	delete my_gui;
	delete window;
	return 0;
}

