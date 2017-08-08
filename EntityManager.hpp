//
// Created by Estevan Hernandez on 8/7/17.
//

#ifndef ORIGAMISPACETIME_ENTITYMANAGER_HPP
#define ORIGAMISPACETIME_ENTITYMANAGER_HPP

#include <vector>
#include "Entity.hpp"

class EntityManager {
protected:
    std::vector<Entity *> entities_;
public:
    const std::vector<Entity *> &entities = entities_;
    void addEntity(Entity *entity);
    void removeEntity(Entity *entity);
};

#endif //ORIGAMISPACETIME_ENTITYMANAGER_HPP
