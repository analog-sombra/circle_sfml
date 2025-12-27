#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#include <SFML/Graphics.hpp>

class Circle
{
public:
    Circle(float radius, sf::Color color, sf::Vector2f position, sf::Vector2f velocity);
    void draw(sf::RenderWindow &window);
    void update(float deltaTime);
    bool getIsDead() const { return isDead; }


private:
    sf::Color color;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::CircleShape shape;
    float lifetime;
    bool isDead;
};

#endif // __CIRCLE_HPP__