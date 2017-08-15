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
protected:
    World *world_;
    sf::Vector2i position_;
    int &x_ = position_.x;
    int &y_ = position_.y;

    sf::Vector2i size_;
    int &width_ = size_.x;
    int &height_ = size_.y;
public:
    const sf::Vector2i &position = position_;
    const sf::Vector2i &size = size_;
    const int width = width_;
    const int height = height_;
    const int &x = position_.x;
    const int &y = position_.y;

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
};

#endif //SFML_ENGINE_PHYSICSCOMPONENT_HPP
