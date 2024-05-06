#include "Food.h"

Food::Food(int width, int height)
	: width(width), height(height)
{
	newFood();
}

const list<Vector2i>& Food::getFoodsPos() const {
	return pos;
}

void Food::eat(Vector2i foodPos) {
	pos.remove(foodPos);
	newFood();
}

void Food::newFood()
{
	pos.push_back(Vector2i(rand() % width, rand() % height));
}