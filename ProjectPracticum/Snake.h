#pragma once
#include <deque>
#include <conio.h>

const int START_ROW = 10 / 2;
const int START_COL_1 = 20 / 2; 
const int START_COL_2 = 20 / 2 + 1; 

enum class Direction 
{
	UP,
	LEFT,
	DOWN,
	RIGHT,
};

class Snake
{
public:
	Snake();
	const std::deque<std::pair<int, int>> GetSnake() const;
	void ChangeDirection(); 
	void MoveSnake();
	void Grow();
private:
	std::deque<std::pair<int, int>> snake;
	Direction direction;

};