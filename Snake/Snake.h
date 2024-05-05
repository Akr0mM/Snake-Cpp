#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#include "Food.h"

using namespace std;
using namespace sf;

class Snake
{
public:
    int width, height;
    Food food;
    Snake() = default;
    Snake(int width, int height, Food food, float foodSpawnRate);
    const list<Vector2i>& getSnakeBody() const;
    void update();
    void spawnFood(double rand);
    void setDirection(int dir);
    bool isGameOver;
    int score;

private:
    int velX;
    int velY;
    float foodSpawnRate;

    void changeDirection(int dir);
    void foodColision(int x, int y, Vector2i lastPart);
    void newSnake(Vector2i pos);
    void checkGameOver();

    list<int> dirs;
    list<Vector2i> parts;
};

