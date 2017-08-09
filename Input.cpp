//
// Created by Estevan Hernandez on 7/24/17.
//

#include "Input.hpp"

Input *Input::s_instance = nullptr;
InputStruct Input::inputStruct = InputStruct();

const bool debug = false;

Input::Input() {

}
Input::~Input() {

}

void Input::clearInput() {
    inputStruct.upPressed = false;
    inputStruct.downPressed = false;
    inputStruct.leftPressed = false;
    inputStruct.rightPressed = false;
    inputStruct.upReleased = false;
    inputStruct.downReleased = false;
    inputStruct.leftReleased = false;
    inputStruct.rightReleased = false;
    inputStruct.spacePressed = false;
    inputStruct.leftMouseButtonPressed = false;
}

void Input::getInput(sf::RenderWindow &window) {
    clearInput();
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                if (inputStruct.left == false) {
                    inputStruct.leftPressed = true;
                }
                inputStruct.left = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                if (inputStruct.right == false) {
                    inputStruct.rightPressed = true;
                }
                inputStruct.right = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                if (inputStruct.up == false) {
                    inputStruct.upPressed = true;
                }
                inputStruct.up = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                if (inputStruct.down == false) {
                    inputStruct.downPressed = true;
                }
                inputStruct.down = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                inputStruct.spacePressed = true;
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Left
                || event.key.code == sf::Keyboard::A) {
                if (inputStruct.left == true) {
                    inputStruct.leftReleased = true;
                }
                inputStruct.left = false;
            }
            if (event.key.code == sf::Keyboard::Right
                || event.key.code == sf::Keyboard::D) {
                if (inputStruct.right == true) {
                    inputStruct.rightReleased = true;
                }
                inputStruct.right = false;
            }
            if (event.key.code == sf::Keyboard::Up
                || event.key.code == sf::Keyboard::W) {
                if (inputStruct.up == true) {
                    inputStruct.upReleased = true;
                }
                inputStruct.up = false;
            }
            if (event.key.code == sf::Keyboard::Down
                || event.key.code == sf::Keyboard::S) {
                if (inputStruct.down == true) {
                    inputStruct.downReleased = true;
                }
                inputStruct.down = false;
            }
        } else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                inputStruct.leftMouseButtonPressed = true;
            }
        }
    }
    if (debug) inputStruct.log();
}