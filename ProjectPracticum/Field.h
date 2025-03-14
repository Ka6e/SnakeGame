#pragma once
#include "Snake.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>



class Field
{
public:
	Field();
	void PrintField();
	void PlaceApple();
	void DrawSnake(const Snake &snake); //��� �����������
	bool IsEatenApple(Snake &snake);
	bool CheckGameStatus(Snake &snake);
	//����� GetField
private:
	std::vector<std::vector<char>> field;
	std::pair<int,int> apple;

};
