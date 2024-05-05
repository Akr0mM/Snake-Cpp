#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <list>

using namespace std;
using namespace sf;

class Food
{
public:
	int width, height;
	Food() = default;
	Food(int width, int height);
	const list<Vector2i>& getFoodsPos() const;
	void eat(Vector2i pos);
	void newFood();

private:
	list<Vector2i> pos;
	void eatSoundEffect();
};

