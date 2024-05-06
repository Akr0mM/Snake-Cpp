#include "Snake.h"

Snake::Snake(int width, int height, Food food, float foodSpawnRate)
	: width(width), height(height), food(food), foodSpawnRate(foodSpawnRate)
{
	isGameOver = false;
	score = 0;
	parts.push_back(Vector2i(rand() % width, rand() % height));

	setDirection(1);
}

const list<Vector2i>& Snake::getSnakeBody() const {
	return parts;
}

void Snake::update() {
	if (!dirs.empty())
	{
		changeDirection(dirs.front());
		dirs.pop_front();
	}

	Vector2i lastPart = parts.back();

	int x = parts.front().x;
	int y = parts.front().y;

	parts.push_front(parts.front());
	parts.pop_back();

	x += velX;
	y += velY;

	if (x < 0)
		x = width - 1;
	else if (x >= width)
		x = 0;

	if (y < 0)
		y = height - 1;
	else if (y >= height)
		y = 0;


	parts.front() = Vector2i(x, y);
	
	checkGameOver();
	foodColision(x, y, lastPart);
}

void Snake::checkGameOver()
{
	if (parts.size() >= 2) {
		Vector2i head = parts.front();

		auto it = std::next(parts.begin());

		while (it != parts.end()) {
			if (it->x == head.x && it->y == head.y) {
				cout << "Game Over !" << endl << "Score : " << score << endl;
				isGameOver = true;
				break;
			}
			
			++it;
		}
	}
}

void Snake::spawnFood(double rand)
{
	if (rand < foodSpawnRate)
	{
		food.newFood();
	}
}

void Snake::newSnake(Vector2i pos)
{
	parts.push_back(pos);
}

void Snake::foodColision(int x, int y, Vector2i lastPart)
{
	const list<Vector2i> foodPositions = food.getFoodsPos();

	if (!foodPositions.empty()) {
		for (const Vector2i& pos : foodPositions) {
			if (x == pos.x && y == pos.y) {
				food.eat(pos);
				newSnake(lastPart);
				score += 1;
			}
		}

	}
}

void Snake::setDirection(int dir) {
	if (dirs.size() < 2)
		dirs.push_back(dir);
}

void Snake::changeDirection(int dir)
{
	if (dir == 0 && velY != 1)
	{
		velX = 0;
		velY = -1;
	}
	else if (dir == 1 && velX != -1)
	{
		velX = 1;
		velY = 0;
	}
	else if (dir == 2 && velY != -1)
	{
		velX = 0;
		velY = 1;
	}
	else if (dir == 3 && velX != 1)
	{
		velX = -1;
		velY = 0;
	}
}