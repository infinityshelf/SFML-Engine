//
// Created by Estevan Hernandez on 8/7/17.
//

#ifndef ORIGAMISPACETIME_COLLIDABLEMANAGER_HPP
#define ORIGAMISPACETIME_COLLIDABLEMANAGER_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class CollidableManager {
protected:
    std::vector<sf::Rect<uint16_t> *> collidables_;
    sf::RectangleShape rectShape;
public:
    const std::vector<sf::Rect<uint16_t> *> &collidables = collidables_;
    void addCollidable(sf::Rect<uint16_t> *rect);
    void removeCollidable(sf::Rect<uint16_t> *rect);

    const sf::Rect<uint16_t> *placeFree(const int &x, const int &y, sf::Rect<uint16_t> *rect);
    const sf::Rect<uint16_t> *placeFree(const sf::Vector2f &vector, sf::Rect<uint16_t> *rect);

};


#endif //ORIGAMISPACETIME_COLLIDABLEMANAGER_HPP
