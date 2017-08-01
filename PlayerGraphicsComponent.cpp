//
// Created by Estevan Hernandez on 7/25/17.
//

#include "PlayerGraphicsComponent.hpp"
#include "TextureManager.hpp"
#include "World.hpp"
#include <iostream>
#include <cassert>

const bool debug = false;
const std::string kRobo = "robo";
const std::string kRoboFilePath = "robo.png";

void PlayerGraphicsComponent::update(double elapsed) {
    sprite.setPosition(physicsComponent_.position);
    assert(GraphicsComponent::s_window != nullptr);
    GraphicsComponent::s_window->draw(sprite);
}

PlayerGraphicsComponent::PlayerGraphicsComponent(Entity &entity, PlayerPhysicsComponent &physicsComponent) : physicsComponent_(physicsComponent), GraphicsComponent(entity) {
    TextureManager *textureManager = TextureManager::instance();
    textureManager->loadTexture(kRobo, kRoboFilePath);
    this->sprite.setTexture(TextureManager::instance()->getRef(kRobo));
    this->sprite.setTextureRect(sf::IntRect(0,0,35,81));
    this->sprite.setScale(2,2);
}
