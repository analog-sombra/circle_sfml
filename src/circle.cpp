#include "circle.hpp"
#include "constant.hpp"

Circle::Circle(float radius, sf::Color color, sf::Vector2f position, sf::Vector2f velocity)
    : color(color), position(position), velocity(velocity), shape(radius), lifetime(constant::CIRCLE_LIFETIME), isDead(false)
{
    shape.setFillColor(color);
    shape.setPosition(position);
}
void Circle::draw(sf::RenderWindow &window)
{
    window.draw(shape);
}

void Circle::update(float deltaTime)
{
    lifetime -= deltaTime;
    if (lifetime <= 0)
    {
        isDead = true;
    }

    position += velocity * deltaTime * constant::CIRCLE_SPEED;

    if (position.x < 0 || position.x + shape.getRadius() * 2 > constant::WINDOW_WIDTH)
    {
        velocity.x = -velocity.x;
    }

    if (position.y < 0 || position.y + shape.getRadius() * 2 > constant::WINDOW_HEIGHT)
    {
        velocity.y = -velocity.y;
    }
    shape.setPosition(position);
}