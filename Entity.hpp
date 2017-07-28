#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "World.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Entity {
public:
    virtual void update(double elapsed, sf::RenderWindow &window_ref) = 0;
};

#endif