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

void World::update(double elapsed, sf::RenderWindow &window) {
    window.clear(sf::Color::Black);
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