//
// Created by Estevan Hernandez on 8/7/17.
//

#include "CollidableManager.hpp"
#include <iostream>

const bool debug = false;

void CollidableManager::addCollidable(sf::IntRect *rect) {
    bool shouldAdd = true;
    for (sf::IntRect *aRect : this->collidables) {
        if (aRect == rect) {
            shouldAdd = false;
            break;
        }
    }
    if (shouldAdd == true) {
        this->collidables_.push_back(rect);
    } else {
        if (debug == true) {
            std::cout << "that entity is already in the Worlds entities" << std::endl;
        }
    }
}

void CollidableManager::removeCollidable(sf::IntRect *rect) {
    this->collidables_.erase(std::remove(this->collidables_.begin(), this->collidables_.end(), rect), this->collidables_.end());
}