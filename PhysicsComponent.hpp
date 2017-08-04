//
// Created by Estevan Hernandez on 7/28/17.
//

#ifndef SFML_ENGINE_PHYSICSCOMPONENT_HPP
#define SFML_ENGINE_PHYSICSCOMPONENT_HPP

#include "Entity.hpp"
#include "World.hpp"
#include "Component.hpp"

class PhysicsComponent: public Component {
public:
    PhysicsComponent(Entity &entity): Component(entity), world_(*World::instance()), entity_(entity) {

    }
    const sf::IntRect *placeFree(int x, int y, sf::Rect<int> rect) {
        rect.left = x;
        rect.top = y;
        for (sf::IntRect *collidable : world_.collidables) {
            if (rect.intersects(*collidable)) {
                return collidable;
            }
        }
        return nullptr;

    }
protected:
    World &world_;
    Entity &entity_;
};

#endif //SFML_ENGINE_PHYSICSCOMPONENT_HPP
