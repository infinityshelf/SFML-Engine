//
// Created by Estevan Hernandez on 7/28/17.
//

#ifndef SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP
#define SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP

#include "PhysicsComponent.hpp"

class PlayerPhysicsComponent: public PhysicsComponent {
public:
    int moveSpeed() { return moveSpeed_; }
    int jumpHeight() { return jumpHeight_; };
    const sf::Vector2i &getPosition() { return position_; };
    PlayerPhysicsComponent(Entity &entity);
    void update(double elapsed) override;
    void setProposedVector(sf::Vector2i &proposedVector) {
        proposedVector_ = &proposedVector;
    }
    void siblingComponentsInitialized() override;
    const bool *grounded = &grounded_;
private:
    bool grounded_;
    sf::Vector2i position_;
    int &x = position_.x;
    int &y = position_.y;
    sf::IntRect boundingBox_;

    sf::Vector2i *proposedVector_;
    int max_up;
    int max_right;
    int max_left;
    int max_down;
    void clampValues(sf::Vector2i *vector);
    const int moveSpeed_ = 2;
    const int jumpHeight_ = 50;
};


#endif //SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP
