#include "game.hpp"
#include <SFML/Graphics.hpp>
#include "constant.hpp"
#include <stdio.h>
#include "circle.hpp"
#include "utils.hpp"
#include <SFML/Window.hpp>

Game::Game() : context(std::make_shared<Context>())
{
    context->window->create(sf::VideoMode({constant::WINDOW_WIDTH, constant::WINDOW_HEIGHT}), constant::WINDOW_TITLE);
}

void Game::run()
{

    sf::Clock clock;

    while (context->window->isOpen())
    {
        while (const std::optional event = context->window->pollEvent())
        {

            // close event
            if (event->is<sf::Event::Closed>())
                context->window->close();

            // mouse move event
            if (event->is<sf::Event::MouseMoved>())
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*context->window);
                fire(mousePos);
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
            {
                context->shapes.clear();
            }

            // if (event->is<sf::Event::KeyPressed>())
            // {
            //     auto key = event->getIf<sf::Event::KeyPressed>();
            //     if (key->code == sf::Keyboard::Key::Space)
            //     {
            //         float radius = Utils::getRandomRadius();
            //         Circle newCircle(
            //             radius,
            //             Utils::getRandomColor(),
            //             Utils::getRandomPosition(radius),
            //             Utils::getRandomVelocity());
            //         context->shapes.push_back(std::make_unique<Circle>(newCircle));
            //     }
            // }
        }

        float deltaTime = clock.restart().asSeconds();

        context->window->clear(sf::Color::Black);

        for (size_t i = 0; i < context->shapes.size(); ++i)
        {
            context->shapes[i]->draw(*context->window);
            context->shapes[i]->update(deltaTime);
        }
        // Remove dead entities
        std::erase_if(context->shapes, [](const auto &e)
                      { return e->getIsDead(); });

        context->window->display();
    }
}

void Game::fire(sf::Vector2i position)
{

    int circle_count = 5;
    for (int i = 0; i < circle_count; ++i)
    {
        float radius = Utils::getRandomRadius();
        Circle newCircle(
            radius,
            Utils::getRandomColor(),
            sf::Vector2f(static_cast<float>(position.x), static_cast<float>(position.y)),
            Utils::getRandomVelocity());
        context->shapes.push_back(std::make_unique<Circle>(newCircle));
    }
}