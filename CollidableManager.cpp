//
// Created by Estevan Hernandez on 8/7/17.
//

#include "CollidableManager.hpp"
#include <iostream>

const bool debug = false;

void CollidableManager::addCollidable(sf::Rect<uint16_t> *rect) {
    bool shouldAdd = true;
    for (sf::Rect<uint16_t> *aRect : this->collidables) {
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

void CollidableManager::removeCollidable(sf::Rect<uint16_t> *rect) {
    this->collidables_.erase(std::remove(this->collidables_.begin(), this->collidables_.end(), rect), this->collidables_.end());
}

const sf::Rect<uint16_t> *CollidableManager::placeFree(const int &x, const int &y, sf::Rect<uint16_t> *rect) {
    rect->left = x;
    rect->top = y;
    for (sf::Rect<uint16_t> *collidable : collidables) {
        if (rect->intersects(*collidable)) {
            return collidable;
        }
    }
    return nullptr;
}

const sf::Rect<uint16_t> *CollidableManager::placeFree(const sf::Vector2f &vector, sf::Rect<uint16_t> *rect) {
    return placeFree(vector.x, vector.y, rect);
}
