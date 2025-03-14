#include "Field.h"
#include "Snake.h"
#include "Ñonstants.h"

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