//
// Created by Estevan Hernandez on 8/7/17.
//

#ifndef ORIGAMISPACETIME_GAMEWORLD_HPP
#define ORIGAMISPACETIME_GAMEWORLD_HPP

#include "World.hpp"

class GameWorld: public World {
private:
    GameWorld();
    static GameWorld *s_instance;
public:
    static GameWorld *instance();
    ~GameWorld();
};


#endif //ORIGAMISPACETIME_GAMEWORLD_HPP
