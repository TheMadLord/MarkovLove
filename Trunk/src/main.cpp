// reading a text file
#include <iostream>
#include <fstream>
#include <string>

#include "parser.hpp"
#include "gui.hpp"
#include "button.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Mouse.hpp>

using namespace std;

int main () {

    parseFile("L1t.txt");

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
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window->close();
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            // collision w/ buttons
            // CHANGE 'CAUSE BUTTONS ARE STORED DIFFERENTLY AS OF RN
            /*
            for (std::map<std::string, sf::Sprite>::iterator iter = my_gui->main_menu_buttons.begin(); iter != my_gui->main_menu_buttons.end(); iter++) {
                if (my_gui->iter->second->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*my_window)))) {
                    // is colliding
                }
            }
            */
        }

        // UPDATE
        deltaTime = clock.restart().asSeconds();

        // RENDER
        my_gui->my_window->clear(sf::Color::Black);

        // ALL DRAW CODE GOES HERE.
        //maybe eventually move this all to the my_gui->update() function
        my_gui->my_window->draw(my_gui->getBkg(my_gui->current_background));
        if (my_gui->current_state == "menu"){
            for (std::map<std::string, button*>::iterator iter = my_gui->main_menu_buttons.begin(); iter != my_gui->main_menu_buttons.end(); iter++) {
                my_gui->my_window->draw(iter->second->getSprite());
            }
        } else if (my_gui->current_state == "date"){
            for (std::map<std::string, button*>::iterator iter = my_gui->on_date_buttons.begin(); iter != my_gui->on_date_buttons.end(); iter++) {
                my_gui->my_window->draw(iter->second->getSprite());
            }
            my_gui->my_window->draw(my_gui->getGirl(my_gui->current_girl));
        } else if (my_gui->current_state == "overworld"){
            for (std::map<std::string, button*>::iterator iter = my_gui->overworld_buttons.begin(); iter != my_gui->overworld_buttons.end(); iter++) {
                my_gui->my_window->draw(iter->second->getSprite());
            }
            my_gui->my_window->draw(my_gui->getGirl(my_gui->current_girl));
        } else {
            std::cout << "CURRENT STATE NOT VALID" << std::endl;
            break;
        }
        //my_gui->my_window->draw(my_gui->getGirl(my_gui->current_girl)); // might have to alter depending on frame and on_date/not

        my_gui->my_window->display();
    }
	delete my_gui;
	delete window;
	return 0;
}

