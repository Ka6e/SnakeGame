#include "Snake.h"

Snake::Snake()
{
	direction = Direction::LEFT;
	snake.push_back({ START_ROW, START_COL_1 });
	snake.push_back({ START_ROW, START_COL_2 });
};

const std::deque<std::pair<int, int>> Snake::GetSnake() const
{
	return snake;
};

void Snake::ChangeDirection()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			if (direction != Direction::DOWN) direction = Direction::UP;
			break;
		case 'a':
			if (direction != Direction::RIGHT)direction = Direction::LEFT;
			break;
		case 's':
			if (direction != Direction::UP) direction = Direction::DOWN;
			break;
		case 'd':
			if (direction != Direction::LEFT) direction = Direction::RIGHT;
			break;
		default:
			break;
		}
	}
};

void Snake::MoveSnake()
{
	std::pair<int, int> head = snake.front();

	switch (direction)
	{
	case Direction::UP:
		head.first--;
		break;
	case Direction::LEFT:
		head.second--;
		break;
	case Direction::DOWN:
		head.first++;
		break;
	case Direction::RIGHT:
		head.second++;
		break;
	default:
		break;
	}

	snake.push_front(head);
	snake.pop_back();
};

void Snake::Grow()
{
	snake.push_back(snake.back());
};




