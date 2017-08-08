//
// Created by Estevan Hernandez on 7/28/17.
//

#ifndef SFML_ENGINE_PHYSICSCOMPONENT_HPP
#define SFML_ENGINE_PHYSICSCOMPONENT_HPP

#include "Entity.hpp"
#include "World.hpp"
#include "Component.hpp"
#include <cassert>

class PhysicsComponent: public Component {
public:
    PhysicsComponent(Entity &entity): Component(entity) {

    }
    const sf::IntRect *placeFree(const int &x, const int &y, sf::Rect<int> rect) {
        rect.left = x;
        rect.top = y;
        assert(world_ != nullptr && "world_ was null. Did you provide it in the Derived Class's Constructor?");
        World &world = *world_;
        for (sf::IntRect *collidable : world.collidables) {
            if (rect.intersects(*collidable)) {
                return collidable;
            }
        }
        return nullptr;
    }
    const sf::IntRect *placeFree(const sf::Vector2i &vector, sf::Rect<int> rect) {
        return placeFree(vector.x, vector.y, rect);
    }
protected:
    World *world_;
};

#endif //SFML_ENGINE_PHYSICSCOMPONENT_HPP
