#pragma once
#include <deque>
#include <conio.h>

const int START_ROW = 10 / 2;
const int START_COL_1 = 20 / 2; //переименовать
const int START_COL_2 = 20 / 2 + 1; //переименовать

enum class Direction //отдельно вынести
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
	void ChangeDirection(); //изменить возвращение 
	void MoveSnake();
	void Grow();
private:
	std::deque<std::pair<int, int>> snake;
	Direction direction;

};