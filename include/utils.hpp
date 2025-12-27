#ifndef __UTILS_CPP__
#define __UTILS_CPP__
#include <SFML/Graphics.hpp>
namespace Utils
{
    float getRandomRadius();
    sf::Color getRandomColor();
    sf::Vector2f getRandomPosition(float radius);
    sf::Vector2f getRandomVelocity();
    
} // namespace Utils


#endif // __UTILS_CPP__