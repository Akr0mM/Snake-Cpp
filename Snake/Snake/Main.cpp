#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <list>

#include "Snake.h"
#include "Food.h"

using namespace std;
using namespace sf;

int main()
{
    Music music;

    if (!music.openFromFile("assets/music.ogg")) {
        cout << "Failed to load music" << endl;
    }

    music.setVolume(10);
    music.setLoop(true);
    music.play();

    int bs = 15;
    int width = 80;
    int height = 54;
    float foodSpawnRate = 0.05f;

    srand(time(nullptr));

    RenderWindow window(VideoMode(width * bs, height * bs), "Snake");

    Food food(width, height);
    Snake snake(width, height, food, foodSpawnRate);

    Clock clock;
    float timer = 0.0f;
    float delay = 0.1f; // speed // fps // foodSpawnRate

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Q))
            {
                window.close();
            }

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Up)
                    snake.setDirection(0);
                else if (event.key.code == Keyboard::Right)
                    snake.setDirection(1);
                else if (event.key.code == Keyboard::Down)
                    snake.setDirection(2);
                else if (event.key.code == Keyboard::Left)
                    snake.setDirection(3);
            }
        }

        if (!snake.isGameOver) {    
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
        }

        if (timer > delay) {
            timer = 0;
            snake.update();
            snake.spawnFood(static_cast<double>(std::rand()) / RAND_MAX);
        }

        window.clear();

        // Dessiner les aliments
        for (const auto& pos : snake.food.getFoodsPos())
        {
            RectangleShape square(Vector2f(bs, bs));
            square.setPosition(Vector2f(pos.x * bs, pos.y * bs));
            square.setFillColor(Color::Green);
            window.draw(square);
        }

        // Dessiner le serpent
        for (const auto& pos : snake.getSnakeBody())
        {
            RectangleShape square(Vector2f(bs, bs));
            square.setPosition(Vector2f(pos.x * bs, pos.y * bs));
            square.setFillColor(Color::White);
            window.draw(square);
        }


        window.display();
    }

    return 0;
}
