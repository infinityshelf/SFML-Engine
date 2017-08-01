//
// Created by Estevan Hernandez on 7/28/17.
//

#include "PlayerPhysicsComponent.hpp"
#include "Player.hpp"

const bool debug = false;

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity &entity): PhysicsComponent(entity) {
    boundingBox.width = 35 * 2;
    boundingBox.height = 81 * 2;
}

void PlayerPhysicsComponent::update(double elapsed) {
    if (debug) std::cout << "elapsed: " << elapsed << std::endl;
    position += *proposedVector_;
    boundingBox.left = position.x + proposedVector_->x;
    boundingBox.top = position.y + proposedVector_->y;
    for (sf::IntRect *rect: world_.collidables) {
        if (boundingBox.intersects(*rect)) {
            if (proposedVector_->x > 0.0f) {
                position.x = rect->left - boundingBox.width;
            } else if (proposedVector_->x < 0.0f) {
                position.x = rect->left + rect->width;
            } else {
                // no x movement
            }
            if (proposedVector_->y > 0.0f) {
                position.y = rect->top - boundingBox.height;
            } else if (proposedVector_->y < 0.0f) {
                position.y = rect->top + rect->height;
            } else {
                // no y movement
            }
            if (debug) std::cout << "There is a collision!" << std::endl;

        }
    }
}
