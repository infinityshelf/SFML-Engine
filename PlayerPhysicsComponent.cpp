//
// Created by Estevan Hernandez on 7/28/17.
//

#include "PlayerPhysicsComponent.hpp"
#include "Player.hpp"

PlayerPhysicsComponent::PlayerPhysicsComponent() {
    World::instance()->addCollidable(&boundingBox);
    boundingBox.width = 35;
    boundingBox.height = 81;
    world = World::instance();
    world->addCollidable(&boundingBox);
}

void PlayerPhysicsComponent::update(double elapsed, Entity &entity) {
    Player *player = (Player *)&entity;

    boundingBox.left = entity.position.x;
    boundingBox.top = entity.position.y;
}