

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

sf::Vector2f Utils::getRandomPosition(float radius)
{
    static std::mt19937 gen(std::random_device{}());

    constexpr float SAFE_PADDING = 2.f;

    std::uniform_real_distribution<float> disX(
        radius + SAFE_PADDING,
        constant::WINDOW_WIDTH - radius - SAFE_PADDING);

    std::uniform_real_distribution<float> disY(
        radius + SAFE_PADDING,
        constant::WINDOW_HEIGHT - radius - SAFE_PADDING);

    return {disX(gen), disY(gen)};
}

sf::Vector2f Utils::getRandomVelocity()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> dis(-1.f, 1.f);
    return sf::Vector2f(dis(gen), dis(gen));
}