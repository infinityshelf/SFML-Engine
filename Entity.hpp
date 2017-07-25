#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "World/World.hpp"
#include <SFML/Graphics.hpp>

class Entity {
public:
    virtual void update(double elapsed, sf::RenderWindow &window) = 0;
};

#endif