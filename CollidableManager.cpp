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

const sf::IntRect *CollidableManager::placeFree(const int &x, const int &y, sf::Rect<int> rect) {
    rect.left = x;
    rect.top = y;
    for (sf::IntRect *collidable : collidables) {
        if (rect.intersects(*collidable)) {
            return collidable;
        }
    }
    return nullptr;
}

const sf::IntRect *CollidableManager::placeFree(const sf::Vector2f &vector, sf::Rect<int> rect) {
    return placeFree(vector.x, vector.y, rect);
}
