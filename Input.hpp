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

class Input {
private:
    Input();
    static Input *s_instance;
public:
    static Input *instance() {
        if (!s_instance) {
            s_instance = new Input;
        }
        return s_instance;
    }
    ~Input();
    static InputStruct inputStruct;
    static void getInput(sf::RenderWindow &window_ref);
    static void clearInput();
    static void log();
};

#endif //SFML_ENGINE_INPUT_HPP
