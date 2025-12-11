#include "circle.hpp"

Circle::Circle(float radius, sf::Color color, sf::Vector2f position)
    : color(color), position(position), shape(radius)
{
    shape.setFillColor(color);
    shape.setPosition(position);
}
void Circle::draw(sf::RenderWindow &window)
{
    window.draw(shape);
}

void Circle::update()
{
    // Update logic for the circle
}