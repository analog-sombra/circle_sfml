#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#include <SFML/Graphics.hpp>

class Circle
{
public:
    Circle(float radius, sf::Color color, sf::Vector2f position);
    void draw(sf::RenderWindow &window);
    void update();

private:
    sf::Color color;
    sf::Vector2f position;
    sf::CircleShape shape;
};

#endif // __CIRCLE_HPP__