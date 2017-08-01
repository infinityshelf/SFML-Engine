//
// Created by Estevan Hernandez on 7/28/17.
//

#include "PlayerPhysicsComponent.hpp"
#include "Player.hpp"

const bool debug = false;

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity &entity): PhysicsComponent(entity) {
    bbox.width = 35 * 2;
    bbox.height = 81 * 2;
    position.x = 620 / 2 - bbox.width / 2;
    position.y = 480 / 2 - bbox.height / 2;

}

void PlayerPhysicsComponent::update(double elapsed) {
    if (debug) std::cout << "elapsed: " << elapsed << std::endl;

    proposedVector_->y += 2; //gravity?

    bbox.left = position.x;
    bbox.top = position.y;
    projected_bbox = bbox;

    bool xCollision = false;
    bool yCollision = false;
    for (sf::IntRect *rect: world_.collidables) {
        //check x
        projected_bbox.top = bbox.top;
        projected_bbox.left = bbox.left + proposedVector_->x;

        if (projected_bbox.intersects(*rect)) {
            xCollision = true;
            if (proposedVector_->x > 0) {
                position.x = rect->left - bbox.width;
            } else if (proposedVector_->x < 0) {
                position.x = rect->left + rect->width;
            }
        }
        //check y
        projected_bbox.left = bbox.left;
        projected_bbox.top = bbox.top + proposedVector_->y;
        if (projected_bbox.intersects(*rect)) {
            yCollision = true;
            if (proposedVector_->y > 0) {
                position.y = rect->top - bbox.height;
            } else if (proposedVector_->y < 0) {
                position.y = rect->top + rect->height;
            }
        }
    }
    if (xCollision == false) {
        position.x += proposedVector_->x;
    }
    if (yCollision == false) {
        position.y += proposedVector_->y;
    }
}
