#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity {
public:
    virtual void update(double elapsed) = 0;
};

#endif