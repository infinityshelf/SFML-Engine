//
// Created by Estevan Hernandez on 8/7/17.
//

#ifndef ORIGAMISPACETIME_COLLIDABLEMANAGER_HPP
#define ORIGAMISPACETIME_COLLIDABLEMANAGER_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class CollidableManager {
protected:
    std::vector<sf::IntRect *> collidables_;
    sf::RectangleShape rectShape;
public:
    const std::vector<sf::IntRect *> &collidables = collidables_;
    void addCollidable(sf::IntRect *rect);
    void removeCollidable(sf::IntRect *rect);

};


#endif //ORIGAMISPACETIME_COLLIDABLEMANAGER_HPP
