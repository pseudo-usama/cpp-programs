// snake game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "iostream"
#include "Windows.h"
using namespace std;

bool gameover;
const int width = 40;
const int length = 40;
int x, y, Fx, Fy, score;
int tailX[100], tailY[100];
int ntail;
enum eDirection{ Stop = 0, Left, Right, Up, Down };
eDirection dir;

void Setup()
{
	gameover = false;
	dir = Stop;
	x = width / 2;
	y = length / 2;
	Fx = rand() % width;
	Fy = rand() % length;
	score = 0;
}

void Draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y&&j == x)
				cout << "O";
			else if (i == Fy&&j == Fx)
				cout << "Z";
			else
			{
				bool print = false;
				for (int k = 0; k < ntail; k++)
				{
					if (tailX[k] == j&&tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "Score : " << score << endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = Left;
			break;
		case 'd':
			dir = Right;
			break;
		case 'w':
			dir = Up;
			break;
		case 's':
			dir = Down;
			break;
		case 'p':
			gameover = true;
			break;
		}
	}
}

void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < ntail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case Right:
		x++;
		break;
	case Left:
		x--;
		break;
	case Up:
		y--;
		break;
	case Down:
		y++;
		break;
	default:
		break;
	}
	/*if (x>width || x<0 || y>length || y<0)
	gameover=true;*/

	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= length) y = 0; else if (y < 0) y = length - 1;
	for (int i = 0; i < ntail; i++)
	if (tailX[i] == x&&tailY[i] == y)
		gameover = true;

	if (x == Fx&&y == Fy)
	{
		score += 10;
		Fx = rand() % width;
		Fy = rand() % length;
		ntail++;
	}
}

void main()
{
	Setup();
	Draw();
	while (!gameover)
	{
		Draw();
		Input();
		Logic();
		Sleep(10);
	}
}