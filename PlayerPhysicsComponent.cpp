//
// Created by Estevan Hernandez on 7/28/17.
//

#include "PlayerPhysicsComponent.hpp"
#include "PlayerInputComponent.hpp"

const bool debug = false;

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity &entity): PhysicsComponent(entity) {
    boundingBox_.width = 35 * 2;
    boundingBox_.height = 81 * 2;
    x = 620 / 2 - boundingBox_.width / 2;
    y = 480 / 2 - boundingBox_.height / 2;

    max_left = max_right = 15;
    max_up = 50;
    max_down = 20;

}

void PlayerPhysicsComponent::clampValues(sf::Vector2i *vector) {
    vector->x = (vector->x > max_right) ? max_right : vector->x;
    vector->x = (vector->x < -max_left) ? -max_left : vector->x;
    vector->y = (vector->y > max_down) ? max_down : vector->y;
    vector->y = (vector->y < -max_up) ? -max_up : vector->y;
}

void PlayerPhysicsComponent::update(double elapsed) {
    if (debug) std::cout << "elapsed: " << elapsed << std::endl;


    boundingBox_.left = x;
    boundingBox_.top = y;


    proposedVector_->y += 2; //gravity?

    if (placeFree(x, y - 1, boundingBox_) != nullptr) {
        if (proposedVector_->y < 0) {
            proposedVector_->y = 0;
        }
    }

    clampValues(proposedVector_);

    const sf::IntRect *result;

    result = placeFree(x + proposedVector_->x, y, boundingBox_);

    if (result == nullptr) {
        x += proposedVector_->x;
    } else {
        if (proposedVector_->x > 0) {
            x = result->left - boundingBox_.width;
        } else if (proposedVector_->x < 0) {
            x = result->left + result->width;
        }
    }

    result = placeFree(x , y + proposedVector_->y, boundingBox_);

    if (result == nullptr) {
        y += proposedVector_->y;
    } else {
        if (proposedVector_->y > 0) {
            y = result->top - boundingBox_.height;
        } else if (proposedVector_->y < 0) {
            y = result->top + result->height;
        }
    }
    grounded_ = (placeFree(x, y + 1, boundingBox_) != nullptr);
}

void PlayerPhysicsComponent::siblingComponentsInitialized() {
    proposedVector_ = &entity_.getComponent<PlayerInputComponent *>()->proposedVector();
}
