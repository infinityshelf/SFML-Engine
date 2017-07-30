//
// Created by Estevan Hernandez on 7/28/17.
//

#include "PlayerPhysicsComponent.hpp"
#include "Player.hpp"

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity &entity): PhysicsComponent(entity) {
    World::instance()->addCollidable(&boundingBox);
    boundingBox.width = 35;
    boundingBox.height = 81;
    world_->addCollidable(&boundingBox);
}

void PlayerPhysicsComponent::update(double elapsed) {
    boundingBox.left = entity_.position.x;
    boundingBox.top = entity_.position.y;
}