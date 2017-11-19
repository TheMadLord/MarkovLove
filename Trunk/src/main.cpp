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
    bool click = false;
    bool beginning_of_date = true;
    int choice;
	float deltaTime;
	sf::Clock clock;
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "MarkovLove");
    gui* my_gui = new gui(window);

    vector<string> blooooooop;

    Conversation* c = parseFile("Date1.txt");
    ConversationHandler ch (c);

    //std::cout << std::to_string(my_gui->overworld_buttons["overworld_forrest"]->getRect().height) << std::endl;
    //std::cout << std::to_string(my_gui->overworld_buttons["overworld_forrest"]->getRect().width) << std::endl;

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
            if (click == false) {
                click = true;
                // collision w/ buttons
                if (my_gui->current_state == "menu"){
                    for (std::map<std::string, button*>::iterator iter = my_gui->main_menu_buttons.begin(); iter != my_gui->main_menu_buttons.end(); iter++) {
                        if (iter->second->getRect().contains(sf::Vector2<int>(sf::Mouse::getPosition(*(my_gui->my_window))))) {
                            if (iter->second->getName() == "main_menu_play"){
                                my_gui->current_state = "overworld";
                                my_gui->current_background = "map_bkg";
                                //my_gui->current_girl = "Virgo";
                            } else if (iter->second->getName() == "main_menu_options") {
                                //my_gui->current_state =
                                std::cout << "\noptions" << std::endl;
                                window->close();
                            }
                        }
                    }
                } else if (my_gui->current_state == "overworld"){
                    for (std::map<std::string, button*>::iterator iter = my_gui->overworld_buttons.begin(); iter != my_gui->overworld_buttons.end(); iter++) {
                        std::cout << "bloop" << std::endl;
                        std::cout << iter->second->getName();
                        if (iter->second->getRect().contains(sf::Vector2<int>(sf::Mouse::getPosition(*(my_gui->my_window))))) {
                            if (iter->second->getName() == "overworld_forrest"){
                                my_gui->current_background = "forrest_bkg";
                                my_gui->current_state = "date";
                                my_gui->current_girl = "Virgo";
                            } else if (iter->second->getName() == "overworld_menu") {
                                my_gui->current_background = "main_menu_bkg";
                                my_gui->current_state = "menu";
                                my_gui->current_girl = "none";
                            } else if (iter->second->getName() == "overworld_library") {
                                my_gui->current_background = "library_bkg";
                                my_gui->current_state = "date";
                                my_gui->current_girl = "Virgo";
                            } else if (iter->second->getName() == "overworld_bakery") {
                                my_gui->current_background = "bakery_bkg";
                                my_gui->current_state = "date";
                                my_gui->current_girl = "Virgo";
                            }
                        }
                    }
                } else if (my_gui->current_state == "date") {
                    for (std::map<std::string, button*>::iterator iter = my_gui->overworld_buttons.begin(); iter != my_gui->overworld_buttons.end(); iter++) {
                        if (iter->second->getRect().contains(sf::Vector2<int>(sf::Mouse::getPosition(*(my_gui->my_window))))) {
                            if (iter->second->getName() == "dialog_option_1"){
                                choice = 0;
                            } else if (iter->second->getName() == "dialog_option_2"){
                                choice = 1;
                            } else if (iter->second->getName() == "give_gift"){
                                //open inventory
                                // ha like we're going to get that done
                            } else if (iter->second->getName() == "back_to_menu"){
                                my_gui->current_state = "overworld";
                                my_gui->current_background = "map_bkg";
                                my_gui->current_girl = "none";
                            } else {
                                std::cout << "not a button" << std::endl;
                            }
                        }
                    }
                } else {
                    std::cout << "NOT A VALID STATE - mousepressed" << std::endl;
                }
            }
        } else {
            click = false;
        }

        // UPDATE
        deltaTime = clock.restart().asSeconds();

        // RENDER
        my_gui->my_window->clear(sf::Color::Black);

        // ALL DRAW CODE GOES BETWEEN HERE ---

        my_gui->my_window->draw(my_gui->getBkg(my_gui->current_background));

        if (my_gui->current_girl != "none"){
            if (GIRL_MOOD_ANGRY) {
                my_gui->my_window->draw(my_gui->Virgo_sprites["Virgo_Angry"]);
            } else if (GIRL_MOOD_HAPPY) {
                my_gui->my_window->draw(my_gui->Virgo_sprites["Virgo_Happy"]);
            } else if (GIRL_MOOD_LOVE) {
                my_gui->my_window->draw(my_gui->Virgo_sprites["Virgo_Love"]);
            } else if (GIRL_MOOD_SAD) {
                my_gui->my_window->draw(my_gui->Virgo_sprites["Virgo_Sad"]);
            } else {
                std::cout << "The Girl Maybe Isn't Instantiated ... ?" << std::endl;
            }
        }

        if (my_gui->current_state == "menu"){
            for (std::map<std::string, button*>::iterator iter = my_gui->main_menu_buttons.begin(); iter != my_gui->main_menu_buttons.end(); iter++) {
                my_gui->my_window->draw(iter->second->getSprite());
            }
        } else if (my_gui->current_state == "date"){
            for (std::map<std::string, button*>::iterator iter = my_gui->date_buttons.begin(); iter != my_gui->date_buttons.end(); iter++) {
                my_gui->my_window->draw(iter->second->getSprite());
            }

            std::cout << "before draw date text" << std::endl;
            // DRAW DATE TEXT
            if (beginning_of_date) {
                std::cout << "if" << std::endl;
                blooooooop = ch.getStartText();
                std::cout << "???" << std::endl;
                beginning_of_date = false;
                std::cout << "endif" << std::endl;
            } else {
                std::cout << "else -- SHOULD NOT BE HERE" << std::endl;
                blooooooop = ch.getText(choice);
            }
            std::cout << "before drawText" << std::endl;
            for(int i = 0; i < 3; i++){
                my_gui->drawText(blooooooop[i], my_gui->text_positions[i]);
                std::cout << "got through drawText function" << std::endl;
            }

        } else if (my_gui->current_state == "overworld"){
            for (std::map<std::string, button*>::iterator iter = my_gui->overworld_buttons.begin(); iter != my_gui->overworld_buttons.end(); iter++) {
                my_gui->my_window->draw(iter->second->getSprite());
            }
        } else {
            std::cout << "CURRENT STATE NOT VALID" << std::endl;
            my_gui->my_window->close();
        }

        // --- AND HERE.
        my_gui->my_window->display();
    }
	delete my_gui;
	delete window;
	return 0;
}

