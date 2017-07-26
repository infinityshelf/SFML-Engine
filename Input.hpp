//
// Created by Estevan Hernandez on 7/24/17.
//

#ifndef SFML_ENGINE_INPUT_HPP
#define SFML_ENGINE_INPUT_HPP

#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "InputStruct.hpp"
#include "InputListener.hpp"

class Input
{
private:
    Input();
    static Input *s_instance;
    std::vector<InputListener *> listeners;
    void clearInput();
    void informListeners();
public:
    static Input *instance() {
        if (!s_instance) {
            s_instance = new Input;
        }
        return s_instance;
    }
    ~Input();
    InputStruct inputStruct;
    void addListener(InputListener *listener);
    void removeListener(InputListener *listener);
    void getInput(sf::RenderWindow &window_ref);

    void upPressed();
    void downPressed();
    void leftPressed();
    void rightPressed();

    void upReleased();
    void downReleased();
    void leftReleased();
    void rightReleased();

    void up();
    void down();
    void left();
    void right();

    void enterPressed();

    void processEvent(sf::Event &event);
};

#endif //SFML_ENGINE_INPUT_HPP
