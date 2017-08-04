//
// Created by Estevan Hernandez on 7/28/17.
//

#include "PlayerPhysicsComponent.hpp"

const bool debug = false;

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity &entity): PhysicsComponent(entity) {
    boundingBox_.width = 35 * 2;
    boundingBox_.height = 81 * 2;
    position_.x = 620 / 2 - boundingBox_.width / 2;
    position_.y = 480 / 2 - boundingBox_.height / 2;

    max_left = max_right = 15;
    max_up = 50;
    max_down = 15;

}

void PlayerPhysicsComponent::clampValues(sf::Vector2i *vector) {
    vector->x = (vector->x > max_right) ? max_right : vector->x;
    vector->x = (vector->x < -max_left) ? -max_left : vector->x;
    vector->y = (vector->y > max_down) ? max_down : vector->y;
    vector->y = (vector->y < -max_up) ? -max_up : vector->y;
}

void PlayerPhysicsComponent::update(double elapsed) {
    if (debug) std::cout << "elapsed: " << elapsed << std::endl;


    boundingBox_.left = position_.x;
    boundingBox_.top = position_.y;


    proposedVector_->y += 2; //gravity?

    if (placeFree(position_.x, position_.y - 1, boundingBox_) != nullptr) {
        if (proposedVector_->y < 0) {
            proposedVector_->y = 0;
        }
    }

    clampValues(proposedVector_);

    const sf::IntRect *result;

    result = placeFree(position_.x + proposedVector_->x, position_.y, boundingBox_);

    if (result == nullptr) {
        position_.x += proposedVector_->x;
    } else {
        if (proposedVector_->x > 0) {
            position_.x = result->left - boundingBox_.width;
        } else if (proposedVector_->x < 0) {
            position_.x = result->left + result->width;
        }
    }

    result = placeFree(position_.x , position_.y + proposedVector_->y, boundingBox_);

    if (result == nullptr) {
        position_.y += proposedVector_->y;
    } else {
        if (proposedVector_->y > 0) {
            position_.y = result->top - boundingBox_.height;
        } else if (proposedVector_->y < 0) {
            position_.y = result->top + result->height;
        }
    }
}

bool PlayerPhysicsComponent::onGround() {
    return (placeFree(position_.x, position_.y - 1, boundingBox_) == nullptr) ? true : false;
}
