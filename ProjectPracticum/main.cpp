#include "Field.h"
#include "Snake.h"
//��������� � ���������� ����

const DWORD SNAKESPEED = 250; // ���� ���������

int main()
{
	Field field;
	Snake snake;
	 
	while (field.CheckGameStatus(snake))
	{
		field.PrintField();
		snake.ChangeDirection();
		snake.MoveSnake();
		field.DrawSnake(snake);
		field.IsEatenApple(snake);
		Sleep(SNAKESPEED);
	}

};