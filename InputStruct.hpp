//
// Created by Estevan Hernandez on 7/24/17.
//

#ifndef SFML_ENGINE_INPUTSTRUCT_HPP
#define SFML_ENGINE_INPUTSTRUCT_HPP

#include <iostream>

struct INPUT_STRUCT {
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    bool upPressed = false;
    bool downPressed = false;
    bool leftPressed = false;
    bool rightPressed = false;
    bool upReleased = false;
    bool downReleased = false;
    bool leftReleased = false;
    bool rightReleased = false;
    bool spacePressed = false;
    void log() {
        if (upPressed) std::cout << "upPressed" << std::endl;
        if (downPressed) std::cout << "downPressed" << std::endl;
        if (leftPressed) std::cout << "leftPressed" << std::endl;
        if (rightPressed) std::cout << "rightPressed" << std::endl;
        if (up) std::cout << "up" << std::endl;
        if (down) std::cout << "down" << std::endl;
        if (left) std::cout << "left" << std::endl;
        if (right) std::cout << "right" << std::endl;
        if (upReleased) std::cout << "upReleased" << std::endl;
        if (downReleased) std::cout << "downReleased" << std::endl;
        if (leftReleased) std::cout << "leftReleased" << std::endl;
        if (rightReleased) std::cout << "rightReleased" << std::endl;
        if (spacePressed) std::cout << "spacePressed" << std::endl;
    }
};
typedef INPUT_STRUCT InputStruct;

#endif //SFML_ENGINE_INPUTSTRUCT_HPP