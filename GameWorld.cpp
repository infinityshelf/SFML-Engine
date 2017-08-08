//
// Created by Estevan Hernandez on 8/7/17.
//

#include "GameWorld.hpp"

GameWorld *GameWorld::s_instance = nullptr;

GameWorld::~GameWorld() {

}

GameWorld::GameWorld() {

}

GameWorld *GameWorld::instance() {
    if (!s_instance) {
        s_instance = new GameWorld;
    }
    return s_instance;
}
