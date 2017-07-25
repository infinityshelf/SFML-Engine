#ifndef PLAYER_HPP
#define PLAYER_HPP value

#include <SFML/Graphics.hpp>
#include "../Entity.hpp"

class Player: public Entity {
public:
    Player() {
        position.x = 30.0f;
        position.y = 20.0f;
        
        circleBlue.setRadius(25);
        circleBlue.setPosition(position);
        circleBlue.setOrigin(sf::Vector2f(0.0f,0.0f));
        circleBlue.setOutlineThickness(1);
        circleBlue.setOutlineColor(sf::Color::Blue);
        circleBlue.setFillColor(sf::Color::Transparent);
        
        position.y += 50;
        circleRed.setRadius(25);
        circleRed.setPosition(position);
        circleRed.setOrigin(sf::Vector2f(0.0f,0.0f));
        circleRed.setOutlineThickness(1);
        circleRed.setOutlineColor(sf::Color::Red);
        circleRed.setFillColor(sf::Color::Transparent);
    };
    ~Player();
    void update(double elapsed, sf::RenderWindow &window) override;
private:
    sf::Vector2f position;
    sf::CircleShape circleBlue;
    sf::CircleShape circleRed;
};

#endif