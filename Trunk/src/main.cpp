// reading a text file
#include <iostream>
#include <fstream>
#include <string>

#include "parser.hpp"
#include "girl.hpp"
#include "gui.hpp"
#include "button.hpp"


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Mouse.hpp>

using namespace std;

int main () {



	float deltaTime;
	sf::Clock clock;
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "MarkovLove");
    gui* my_gui = new gui(window);

    parseFile("Date1.txt");
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
            if (my_gui->current_state == "menu"){
                for (std::map<std::string, button*>::iterator iter = my_gui->main_menu_buttons.begin(); iter != my_gui->main_menu_buttons.end(); iter++) {
                    if (iter->second->getRect().contains(sf::Vector2<int>(sf::Mouse::getPosition(*(my_gui->my_window))))) {
                        if (iter->second->getName() == "main_menu_play"){
                            my_gui->current_state = "date"; // CHANGE
                            my_gui->current_girl = "Virgo";
                            my_gui->current_background = "forrest_spr"; // CHANGE
                        } else if (iter->second->getName() == "main_menu_options") {
                            //my_gui->current_state =
                            std::cout << "\noptions" << std::endl;
                            window->close();
                        }
                        //my_gui->button_functions[iter->second->getName()]();
                    }
                }
            } else if (my_gui->current_state == "overworld"){
                for (std::map<std::string, button*>::iterator iter = my_gui->overworld_buttons.begin(); iter != my_gui->overworld_buttons.end(); iter++) {
                    if (iter->second->getRect().contains(sf::Vector2<int>(sf::Mouse::getPosition(*(my_gui->my_window))))) {
                        // stuff
                    }
                }
            } else if (my_gui->current_state == "date"){
                for (std::map<std::string, button*>::iterator iter = my_gui->overworld_buttons.begin(); iter != my_gui->overworld_buttons.end(); iter++) {
                    if (iter->second->getRect().contains(sf::Vector2<int>(sf::Mouse::getPosition(*(my_gui->my_window))))) {
                        if (iter->second->getName() == "dialog_option_1"){
                            //
                        } else if (iter->second->getName() == "dialog_option_2"){
                            //
                        } else if (iter->second->getName() == "give_gift"){
                            //open inventory
                            // ha like we're going to get that done
                        } else if (iter->second->getName() == "run_away"){
                            my_gui->current_state = "overworld";
                            my_gui->current_background = "map";
                        } else {
                            std::cout << "not a button" << std::endl;
                        }
                    }
                }
            } else {
                std::cout << "NOT A VALID STATE - mousepressed" << std::endl;
            }
        }

        // UPDATE
        deltaTime = clock.restart().asSeconds();

        // RENDER
        my_gui->my_window->clear(sf::Color::Black);

        // ALL DRAW CODE GOES BETWEEN HERE ---

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

        // --- AND HERE.

        my_gui->my_window->display();
    }
	delete my_gui;
	delete window;
	return 0;
}

