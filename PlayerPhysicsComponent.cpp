//
// Created by Estevan Hernandez on 7/28/17.
//

#include "PlayerPhysicsComponent.hpp"
#include "Player.hpp"

const bool debug = false;

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity &entity): PhysicsComponent(entity) {
    //World::instance()->addCollidable(&boundingBox);
    boundingBox.width = 35 * 2;
    boundingBox.height = 81 * 2;
    //world_.addCollidable(&boundingBox);
}

void PlayerPhysicsComponent::update(double elapsed) {
    if (debug) std::cout << "elapsed: " << elapsed << std::endl;
    boundingBox.left = entity_.position.x;
    boundingBox.top = entity_.position.y;
    for (sf::IntRect *rect: world_.collidables) {
        if (boundingBox.intersects(*rect)) {
            if (debug) std::cout << "There is a collision!" << std::endl;
            //entity_.position.x = rect->left + rect->width;
            entity_.position.y = rect->top - boundingBox.height;
        }
    }
}