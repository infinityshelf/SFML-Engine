//
// Created by Estevan Hernandez on 8/7/17.
//

#include "EntityManager.hpp"
#include <iostream>

const bool debug = false;

void EntityManager::addEntity(Entity *entity) {
    bool shouldAdd = true;
    for (Entity *anEntity : this->entities) {
        if (anEntity == entity) {
            shouldAdd = false;
            break;
        }
    }
    if (shouldAdd == true) {
        this->entities_.push_back(entity);
    } else {
        if (debug == true) {
            std::cout << "that entity is already in the Worlds entities" << std::endl;
        }
    }
}

void EntityManager::removeEntity(Entity *entity) {
    this->entities_.erase(std::remove(this->entities_.begin(), this->entities_.end(), entity), this->entities_.end());
}