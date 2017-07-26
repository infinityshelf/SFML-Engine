//
// Created by Estevan Hernandez on 7/24/17.
//

#include "Input.hpp"

Input *Input::s_instance = nullptr;
const bool debug = false;

Input::Input() {
    this->clearInput();

}
Input::~Input() {

}

void Input::addListener(InputListener *listener) {
    bool shouldAdd = true;
    for (InputListener *anInputListener : this->listeners) {
        if (anInputListener == listener) {
            shouldAdd = false;
            break;
        }
    }
    if (shouldAdd == true) {
        this->listeners.push_back(listener);
    } else {
        if (debug == true) {
            std::cout << "that listener is already in the Inputs listeners" << std::endl;
        }
    }
}

void Input::removeListener(InputListener *listener) {
    this->listeners.erase(std::remove(this->listeners.begin(), this->listeners.end(), listener), this->listeners.end());
}

void Input::processEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            if (this->inputStruct.left == false) {
                this->inputStruct.leftPressed = true;
            }
            this->inputStruct.left = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            if (this->inputStruct.right == false) {
                this->inputStruct.rightPressed = true;
            }
            this->inputStruct.right = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            if (this->inputStruct.up == false) {
                this->inputStruct.upPressed = true;
            }
            this->inputStruct.up = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            if (this->inputStruct.down == false) {
                this->inputStruct.downPressed = true;
            }
            this->inputStruct.down = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            this->inputStruct.spacePressed = true;
        }
    } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Left
            || event.key.code == sf::Keyboard::A) {
            if (this->inputStruct.left == true) {
                this->inputStruct.leftReleased = true;
            }
            this->inputStruct.left = false;
        }
        if (event.key.code == sf::Keyboard::Right
            || event.key.code == sf::Keyboard::D) {
            if (this->inputStruct.right == true) {
                this->inputStruct.rightReleased = true;
            }
            this->inputStruct.right = false;
        }
        if (event.key.code == sf::Keyboard::Up
            || event.key.code == sf::Keyboard::W) {
            if (this->inputStruct.up == true) {
                this->inputStruct.upReleased = true;
            }
            this->inputStruct.up = false;
        }
        if (event.key.code == sf::Keyboard::Down
            || event.key.code == sf::Keyboard::S) {
            if (this->inputStruct.down == true) {
                this->inputStruct.downReleased = true;
            }
            this->inputStruct.down = false;
        }
    }
}

void Input::getInput(sf::RenderWindow &window) {
    sf::Event event;
    this->clearInput();
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
    }
    this->informListeners();
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
}
void Input::informListeners() {
    if (inputStruct.upPressed) {
        if (debug) {
            std::cout << "Input::upPressed" << std::endl;
        }
        this->upPressed();
    }
    if (inputStruct.leftPressed) {
        if (debug) {
            std::cout << "Input::leftPressed" << std::endl;
        }
        this->leftPressed();
    }
    if (inputStruct.downPressed) {
        if (debug) {
            std::cout << "Input::downPressed" << std::endl;
        }
        this->downPressed();
    }
    if (inputStruct.rightPressed) {
        if (debug) {
            std::cout << "Input::rightPressed" << std::endl;
        }
        this->rightPressed();
    }
    if (inputStruct.up) {
        if (debug) {
            std::cout << "Input::up" << std::endl;
        }
        this->up();
    }
    if (inputStruct.left) {
        if (debug) {
            std::cout << "Input::left" << std::endl;
        }
        this->left();
    }
    if (inputStruct.down) {
        if (debug) {
            std::cout << "Input::down" << std::endl;
        }
        this->down();
    }
    if (inputStruct.right) {
        if (debug) {
            std::cout << "Input::right" << std::endl;
        }
        this->right();
    }
    if (inputStruct.upReleased) {
        if (debug) {
            std::cout << "Input::upReleased" << std::endl;
        }
        this->upReleased();
    }
    if (inputStruct.leftReleased) {
        if (debug) {
            std::cout << "Input::leftReleased" << std::endl;
        }
        this->leftReleased();
    }
    if (inputStruct.rightReleased) {
        if (debug) {
            std::cout << "Input::rightReleased" << std::endl;
        }
        this->rightReleased();
    }
    if (inputStruct.downReleased) {
        if (debug) {
            std::cout << "Input::downReleased" << std::endl;
        }
        this->downReleased();
    }
    if (inputStruct.spacePressed) {
        if (debug) {
            std::cout << "Input::enterPressed" << std::endl;
        }
        this->enterPressed();
    }
}

void Input::leftPressed() {
    for (InputListener *listener : listeners) {
        listener->leftPressed();
    }
}

void Input::upPressed() {
    for (InputListener *listener : listeners) {
        listener->upPressed();
    }
}
void Input::downPressed() {
    for (InputListener *listener : listeners) {
        listener->downPressed();
    }
}
void Input::rightPressed() {
    for (InputListener *listener : listeners) {
        listener->rightPressed();
    }
}

void Input::upReleased() {
    for (InputListener *listener : listeners) {
        listener->upReleased();
    }
}
void Input::downReleased() {
    for (InputListener *listener : listeners) {
        listener->downReleased();
    }
}
void Input::leftReleased() {
    for (InputListener *listener : listeners) {
        listener->leftReleased();
    }
}
void Input::rightReleased() {
    for (InputListener *listener : listeners) {
        listener->rightReleased();
    }
}

void Input::up() {
    for (InputListener *listener : listeners) {
        listener->up();
    }
}
void Input::down() {
    for (InputListener *listener : listeners) {
        listener->down();
    }
}
void Input::left() {
    for (InputListener *listener : listeners) {
        listener->left();
    }
}
void Input::right() {
    for (InputListener *listener : listeners) {
        listener->right();
    }
}

void Input::enterPressed() {
    for (InputListener *listener : listeners) {
        listener->enterPressed();
    }
}