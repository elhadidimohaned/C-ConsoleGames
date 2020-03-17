#include "pch.h"
#include<bits/stdc++.h>
#include<conio.h>
#include<Windows.h>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
bool game_over;
const int wall_height = 22;
const int wall_width = 22;
int fruitX, fruitY;
int snakeX, snakeY;
enum dirc { STOP, UP, DOWN, LEFT, RIGHT };
dirc dir;
int score = 0, lifes = 3;
int tail = 0;
int tailX[100], tailY[100];
int eat = 1;
int sfruitX, sfruitY;
int max_score = 0;
int speed = 100;
int sfruit_track = 1;

void setup()
{
	dir = STOP;
	game_over = false;
	fruitX = rand() % (wall_width - 2) + 1;
	fruitY = rand() % (wall_height - 2) + 1;
	snakeX = wall_width / 2;
	snakeY = wall_height / 2;
}
void play_again()
{
	char c;
	cout << "\nGame Over! your score is: " << score << " .\n";
	cout << "Do you want to play again? y/n: ";
	cin >> c;
	if (c == 'n')
	{
		cout << "Bye!";
		exit(0);
	}
	else if (c == 'y')
	{
		score = 0;
		lifes = 3;
		setup();
	}
	else
	{
		cout << "WRONG INPUT, please try again\n";
		play_again();
	}
}
void draw()
{
	system("cls");
	SetConsoleTextAttribute(h, 9);
	cout << "My snake game V 1.0 HIGHEST SCORE IS ";
	SetConsoleTextAttribute(h, 13);
	cout << max_score << endl;
	SetConsoleTextAttribute(h, 9);
	cout << "Navigate with WASD keys, press ";
	SetConsoleTextAttribute(h, 14);
	cout << "X";
	SetConsoleTextAttribute(h, 9);
	cout << " to terminate.\n";
	SetConsoleTextAttribute(h, 1);
	for (int i = 0; i < wall_width; i++)
		cout << "#";
	SetConsoleTextAttribute(h, 15);
	cout << endl;
	for (int i = 0; i < wall_height; i++)
	{
		for (int j = 0; j < wall_width; j++)
		{
			if (j == 0 || j == wall_height-1)
			{
				SetConsoleTextAttribute(h, 1);
				cout << "#";
				SetConsoleTextAttribute(h, 15);
			}
			else if (i == fruitX && j == fruitY)
			{
				SetConsoleTextAttribute(h, 4);
				cout << "F";
				SetConsoleTextAttribute(h, 15);
			}
			else if (i == snakeX && j == snakeY)
			{
				SetConsoleTextAttribute(h, 2);
				cout << "X";
				SetConsoleTextAttribute(h, 15);
			}
			else if (i == sfruitX && j == sfruitY && eat % 6 == 0)
			{
				SetConsoleTextAttribute(h, 6);
				cout << "S";
				SetConsoleTextAttribute(h, 15);
			}
			else
			{
				bool print = false;
				for (int k = 0; k < tail; k++)
				{
					if (i == tailX[k] && j == tailY[k])
					{
						SetConsoleTextAttribute(h, 2);
						cout << "o";
						SetConsoleTextAttribute(h, 15);
						print = true;
					}
				}
				if (!print)
				{
					cout << " ";
				}
			}
		}
		cout << "\n";
	}
	SetConsoleTextAttribute(h, 1);
	for (int i = 0; i < wall_height; i++)
		cout << "#";
	SetConsoleTextAttribute(h, 15);
	cout << endl;
	cout << "Your score is: " << score << " . Remening lifes are: " << lifes << " ."<<"speed is :"<<(5-(speed/25));
	Sleep(speed);
}
void input()
{
	if (_kbhit())
	{
		char c = _getch();
		if (c == 'a')
		{
			dir = LEFT;
		}
		else if (c == 'd')
		{
			dir = RIGHT;
		}
		else if (c == 'w')
		{
			dir = UP;
		}
		else if (c == 's')
		{
			dir = DOWN;
		}
		else if (c == 'x')
		{
			game_over = true;
		}
	}
}
void logic()
{
	int prevX = tailX[0];
	int	prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = snakeX;
	tailY[0] = snakeY;
	for (int i = 1; i < tail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	if (dir == UP)
	{
		snakeX--;
	}
	else if (dir == DOWN)
	{
		snakeX++;
	}
	else if (dir == LEFT)
	{
		snakeY--;
	}
	else if (dir == RIGHT)
	{
		snakeY++;
	}
	if (snakeY == fruitY && snakeX == fruitX)
	{
		score += 10;
		fruitX = rand() % (wall_width - 2) + 1;
		fruitY = rand() % (wall_height - 2) + 1;
		tail++;
		cout << '\a';
		eat++;
		sfruit_track++;
		if (eat % 5 == 0)
		{
			sfruitX = rand() % (wall_width - 2) + 1;
			sfruitY = rand() % (wall_height - 2) + 1;
		}
	}
	if (snakeY == sfruitY && snakeX == sfruitX)
	{
		score += 100;
		sfruitX = rand() % (wall_width - 2) + 1;
		sfruitY = rand() % (wall_height - 2) + 1;
		tail+=5;
		eat = 1;
		cout << '\a';
	}
	if (score > max_score)
	{
		max_score = score;
	}
	if (sfruit_track % 6 == 0)
	{
		speed -= 25;
		sfruit_track = 1;
		if (speed == -25)
		{
			speed = 0;
		}
	}
	if (snakeX >= wall_width)
	{
		snakeX = 0;
	}
	else if (snakeX < 0)
	{
		snakeX = wall_width - 1;
	}
	if (snakeY >= wall_height-1)
	{
		snakeY = 1;
	}
	else if (snakeY <= 0)
	{
		snakeY = wall_height - 2;
	}
	for (int i = 0; i < tail; i++)
	{
		if (tailX[i] == snakeX && tailY[i] == snakeY)
		{
			lifes--;
			tail = 0;
			speed = 100;
			if (lifes == 0)
			{
				play_again();
			}
		}
	}
}

int main()
{
	srand(time(0));
	setup();

	while (!game_over)
	{
		draw();
		input();
		logic();
	}
	cout << "game over";
	return 0;
}