//
// Created by Estevan Hernandez on 7/24/17.
//

#ifndef SFML_ENGINE_INPUTLISTENER_HPP
#define SFML_ENGINE_INPUTLISTENER_HPP

class InputListener
{
public:
    virtual void upPressed() = 0;
    virtual void downPressed() = 0;
    virtual void leftPressed() = 0;
    virtual void rightPressed() = 0;

    virtual void upReleased() = 0;
    virtual void downReleased() = 0;
    virtual void leftReleased() = 0;
    virtual void rightReleased() = 0;

    virtual void up() = 0;
    virtual void down() = 0;
    virtual void left() = 0;
    virtual void right() = 0;

    virtual void enterPressed() = 0;
};

#endif //SFML_ENGINE_INPUTLISTENER_HPP