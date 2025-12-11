

#include "utils.hpp"
#include "constant.hpp"
#include <random>

float Utils::getRandomRadius()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> dis(constant::MIN_RADIUS, constant::MAX_RADIUS);
    return dis(gen);
}

sf::Color Utils::getRandomColor()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> red(0, 255);
    static std::uniform_int_distribution<int> green(0, 255);
    static std::uniform_int_distribution<int> blue(0, 255);
    return sf::Color(red(gen), green(gen), blue(gen));
}

sf::Vector2f Utils::getRandomPosition()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> disX(0, constant::WINDOW_WIDTH);
    static std::uniform_real_distribution<float> disY(0, constant::WINDOW_HEIGHT);
    return sf::Vector2f(disX(gen), disY(gen));
}