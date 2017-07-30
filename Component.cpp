//
// Created by Estevan Hernandez on 7/30/17.
//

#include "Component.hpp"
int Component::current_id = 0;

Component::Component() {
    current_id++;
    identifier_ = current_id;
}

bool Component::operator==(Component &other) {
    return this->identifier_ == other.identifier_;
}