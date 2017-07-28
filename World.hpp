#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include "Entity.hpp"
#include <SFML/Graphics.hpp>

class Entity;

class World {
private:
    World();
    static World *s_instance;
    std::vector<Entity *> entities;
public:
    static World *instance() {
        if (!s_instance) {
            s_instance = new World;
        }
        return s_instance;
    }
    void addEntity(Entity *entity);
    void removeEntity(Entity *entity);
    ~World();
    void update(double elapsed, sf::RenderWindow &window);
};

#endif