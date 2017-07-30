#include "World.hpp"
#include <iostream>

const bool debug = false;
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

void World::addCollidable(sf::IntRect *rect) {
    bool shouldAdd = true;
    for (sf::IntRect *aRect : this->collidables) {
        if (aRect == rect) {
            shouldAdd = false;
            break;
        }
    }
    if (shouldAdd == true) {
        this->collidables.push_back(rect);
    } else {
        if (debug == true) {
            std::cout << "that entity is already in the Worlds entities" << std::endl;
        }
    }
}

void World::removeCollidable(sf::IntRect *rect) {
    this->collidables.erase(std::remove(this->collidables.begin(), this->collidables.end(), rect), this->collidables.end());
}

void World::update(double elapsed, sf::RenderWindow &window) {
    window.clear(sf::Color(0x20, 0x00, 0x20, 0xFF));
    static double avg;
    avg = (avg + elapsed) / 2.0;
    if (debug) {
        std::cout << "elapsed: " << elapsed << std::endl;
        std::cout << "average: " << avg << std::endl;
    }
    for (Entity *entity: entities) {
        entity->update(elapsed, window);
    }
    window.display();
}