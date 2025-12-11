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

    sf::RenderWindow window(sf::VideoMode({constant::WINDOW_WIDTH, constant::WINDOW_HEIGHT}), constant::WINDOW_TITLE);

    Circle circle(50.f, sf::Color::Green, {100.f, 100.f});
    Circle circle2(75.f, sf::Color::Red, {300.f, 200.f});
    Circle circle3(30.f, sf::Color::Blue, {500.f, 400.f});

    context->shapes.push_back(std::make_unique<Circle>(circle));
    context->shapes.push_back(std::make_unique<Circle>(circle2));
    context->shapes.push_back(std::make_unique<Circle>(circle3));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (event->is<sf::Event::KeyPressed>())
            {
                auto key = event->getIf<sf::Event::KeyPressed>();
                if (key->code == sf::Keyboard::Key::Space)
                {
                    Circle newCircle(
                        Utils::getRandomRadius(),
                        Utils::getRandomColor(),
                        Utils::getRandomPosition());
                    context->shapes.push_back(std::make_unique<Circle>(newCircle));
                }
            }
        }

        window.clear(sf::Color::Black);

        for (size_t i = 0; i < context->shapes.size(); ++i)
        {
            context->shapes[i]->draw(window);
            context->shapes[i]->update();
        }

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        // {

        //     Circle newCircle(
        //         Utils::getRandomRadius(),
        //         Utils::getRandomColor(),
        //         Utils::getRandomPosition());
        //     context->shapes.push_back(std::make_unique<Circle>(newCircle));
        // }
        window.display();
    }
}