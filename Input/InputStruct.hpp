//
// Created by Estevan Hernandez on 7/24/17.
//

#ifndef SFML_ENGINE_INPUTSTRUCT_HPP
#define SFML_ENGINE_INPUTSTRUCT_HPP

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
    };
typedef INPUT_STRUCT InputStruct;

#endif //SFML_ENGINE_INPUTSTRUCT_HPP