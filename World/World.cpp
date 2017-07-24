#include "World.hpp"
#include <iostream>

const bool debug = true;
World *World::s_instance = nullptr;

World::World() {

}

World::~World() {
    
}

void World::addEntity(Entity *entity) {
    bool shouldAdd = true;
    for (Entity *anEntity : this->entities) {
        if (anEntity == entity) {
            shouldAdd = false;
            break;
        }
    }
    if (shouldAdd == true) {
        this->entities.push_back(entity);
    } else {
        if (debug == true) {
            std::cout << "that entity is already in the Worlds entities" << std::endl;
        }
    }
}

void World::removeEntity(Entity *entity) {
    this->entities.erase(std::remove(this->entities.begin(), this->entities.end(), entity), this->entities.end());
}

void World::update(double elapsed) {
    if (debug) {
        std::cout << "elapsed: " << elapsed << std::endl;
    }
}