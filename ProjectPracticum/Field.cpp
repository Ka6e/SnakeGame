#include "Field.h"
#include "Ñonstants.h"

Field::Field()
{
	field.clear();
	std::vector<char> row(COLUMNS, EMPTY);
	for (int i = 0; i < ROWS; i++)
	{
		if (i == 0 || i == ROWS - 1)
		{
			std::fill(row.begin(), row.end(), WALL);
		}
		else
		{
			std::fill(row.begin(), row.end(), EMPTY);
			row[0] = WALL;
			row[COLUMNS - 1] = WALL;
		}
		field.push_back(row);
	}
	PlaceApple();
};


void Field::PlaceApple()
{
	int x, y;
	do
	{
		x = rand() % (ROWS - 2) + 1; 
		y = rand() % (COLUMNS - 2) + 1;

	} while (field[x][y] == WALL || field[x][y] == APPLE);
	field[x][y] = APPLE;
	apple = { x, y };
}

void Field::DrawSnake(const Snake &snake)
{
	for (auto &row : field)
	{
		for (auto &cell : row)
		{
			if (cell == 'S' || cell == 'o')
			{
				cell = EMPTY;
			}
		}
	}
	auto body = snake.GetSnake();
	for (size_t i = 0; i < body.size(); i++)
	{
		int x = body[i].first;
		int y = body[i].second;
		field[x][y] = (i == 0) ? 'S' : 'o';
	}
};


bool Field::IsEatenApple(Snake &snake)
{
	if (snake.GetSnake()[0].first == apple.first && snake.GetSnake()[0].second == apple.second)
	{
		snake.Grow();
		PlaceApple();
		return true;
	}

	return false;
};

bool Field::CheckGameStatus(Snake &snake)
{
	int headX = snake.GetSnake()[0].first;
	int headY = snake.GetSnake()[0].second;
	if (headX == 0 || headX == ROWS - 1 || headY == 0 || headY == COLUMNS - 1)
	{
		std::cout << "You lost!\n";
		return false;
	}

	for (auto i = 1; i < snake.GetSnake().size(); i++)
	{
		if (snake.GetSnake()[0] == snake.GetSnake()[i])
		{
			std::cout << "You lost!\n";
			return false;
		}
	}

	if (IsEatenApple(snake))
	{
		return true;
	}

	bool allFilled = true;
	for (int i = 1; i < ROWS - 1; ++i)
	{
		for (int j = 1; j < COLUMNS - 1; ++j)
		{
			if (field[i][j] != WALL && field[i][j] != APPLE)
			{
				if (field[i][j] != 'S' && field[i][j] != 'o')
				{
					allFilled = false;
					break;
				}
			}
		}
		if (!allFilled)
			break;
	}

	if (allFilled)
	{
		std::cout << "You win! You have filled the entire board!" << std::endl;
		return false;
	}
	return true;
};



void GoToXY(int xPos, int yPos)
{
	COORD Coord = { xPos, yPos };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, Coord);
};

void Field::PrintField()
{
	GoToXY(0, 0);
	for (auto &row : field)
	{
		std::copy(row.begin(), row.end(), std::ostream_iterator<char>(std::cout));
		std::cout << '\n';
	}
};
