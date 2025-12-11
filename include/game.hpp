#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "circle.hpp"

struct Context
{
    std::unique_ptr<sf::RenderWindow> window;
    std::vector<std::unique_ptr<Circle>> shapes;

    Context()
    {
        window = std::make_unique<sf::RenderWindow>();
    }
};

class Game
{
private:
    std::shared_ptr<Context> context;

public:
    Game();
    void run();
};

#endif // __GAME_HPP__