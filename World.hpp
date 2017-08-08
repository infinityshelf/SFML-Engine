#ifndef WORLD_HPP
#define WORLD_HPP

#include "EntityManager.hpp"
#include "CollidableManager.hpp"

class World: public EntityManager, public CollidableManager {
public:
    void update(double elapsed, sf::RenderWindow &window);
};

#endif