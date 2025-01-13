#pragma once
#include "Snake.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

const int ROWS = 10;
const int COLUMNS = 20;
const int START_COLOMN = 2;
const char APPLE = 'A';
const char HEAD = 'S';
const char BODY = 'o';
const char WALL = '#';
const char EMPTY = ' ';


class Field
{
public:
	Field();
	void PrintField();
	void PlaceApple();
	void DrawSnake(const Snake &snake); //тип возвращения
	bool IsEatenApple(Snake &snake);
	bool CheckGameStatus(Snake &snake);
	//метод GetField
private:
	std::vector<std::vector<char>> field;
	std::pair<int,int> apple;

};
