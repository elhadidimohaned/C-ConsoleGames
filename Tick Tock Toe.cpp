#include "pch.h"
#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;

char matrix[3][3] = {'1','2','3','4','5','6','7','8','9'};
char player = 'X';
char again;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
/*HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute(h, 11);

the number is the color 

BLACK 0, BLUE 1, GREEN 2, CYAN 3, RED 4, MAGENTA 5,
	BROWN 6, LIGHT GREY 7, DARK GREY 8, LIGHT BLUE 9,
        LIGHT GREEN 10, LIGHT CYAN 11, LIGHT RED 12, 
	LIGHT MAGENTA 13, YELLOW 14, WHITE 15, */
void Draw()
{
	system("cls");
	SetConsoleTextAttribute(h, 1);
	cout << "My DAMN tick tick toe V1.0\n";
	SetConsoleTextAttribute(h, 15);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] == 'X')
			{
				SetConsoleTextAttribute(h, 2);
				cout << matrix[i][j] << " ";
				SetConsoleTextAttribute(h, 15);
			}
			else if (matrix[i][j] == 'O')
			{
				SetConsoleTextAttribute(h, 4);
				cout << matrix[i][j] << " ";
				SetConsoleTextAttribute(h, 15);
			}
			else
				cout << matrix[i][j] << " ";
			
		}
		cout << endl;
	}
}
void switch_player()
{
	if (player == 'X')
		player = 'O';
	else player = 'X';
}
void input()
{
	char x;
	cout << "It's " << player << " turn, please enter a number: ";
	cin >> x;
	if (x == '1')
	{
		if(matrix[0][0]=='1')
			matrix[0][0] = player;
		else
		{
			cout << "Position is already taken, try another\n";
			input();
		}
	}
	else if (x == '2')
	{
		if (matrix[0][1] == '2')
			matrix[0][1] = player;
		else
		{
			cout << "Position is already taken, try another\n";
			input();
		}
	}
	else if (x == '3')
	{
		if (matrix[0][2] == '3')
			matrix[0][2] = player;
		else
		{
			cout << "Position is already taken, try another\n";
			input();
		}
	}
	else if (x == '4')
	{
		if (matrix[1][0] == '4')
			matrix[1][0] = player;
		else
		{
			cout << "Position is already taken, try another\n";
			input();
		}
	}
	else if (x == '5')
	{
		if (matrix[1][1] == '5')
			matrix[1][1] = player;
		else
		{
			cout << "Position is already taken, try another\n";
			input();
		}
	}
	else if (x == '6')
	{
		if (matrix[1][2] =='6')
			matrix[1][2] = player;
		else
		{
			cout << "Position is already taken, try another\n";
			input();
		}
	}
	else if (x == '7')
	{
		if (matrix[2][0] == '7')
			matrix[2][0] = player;
		else
		{
			cout << "Position is already taken, try another\n";
			input();
		}
	}
	else if (x == '8')
	{
		if (matrix[2][1] == '8')
			matrix[2][1] = player;
		else
		{
			cout << "Position is already taken, try another\n";
			input();
		}
	}
	else if (x == '9')
	{
		if (matrix[2][2] == '9')
			matrix[2][2] = player;
		else
		{
			cout << "Position is already taken, try another\n";
			input();
		}
	}
	else
	{
		cout << "Wrong input, please try again\n";
		input();
	}
	switch_player();
	
}
void choose()
{
	int chose;
	cout << "Choose X-->(1) or O-->(2): ";
	cin >> chose;
	if (chose == 1)
	{
		player = 'X';
	}
	else if (chose == 2)
	{
		player = 'O';
	}
	else
	{
		cout << "WORNG INPUT, try again\n";
		choose();
	}
}
void clear()
{
	matrix[0][0] = '1';
	matrix[0][1] = '2';
	matrix[0][2] = '3';
	matrix[1][0] = '4';
	matrix[1][1] = '5';
	matrix[1][2] = '6';
	matrix[2][0] = '7';
	matrix[2][1] = '8';
	matrix[2][2] = '9';
}
void play_again()
{
	cout << "\nDo you want to play again? y/n: ";
	cin >> again;
	if (again == 'y')
	{
		clear();
		choose();
	}
	else if (again == 'n')
	{
		exit(0);
	}
	else
	{
		cout << "WRONG INPUT,try again";
		play_again();
	}
}
void tie()
{
	int x = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != 'X' && matrix[i][j] != 'O')
				x++;
		}
	}
	if (x == 0)
	{
		Draw();
		cout << "It's a draw!\n";
		play_again();
	}
}
void win()
{
	int checkx = 0;
	int checko = 0;
	if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
	{
		checko++;

	}
	else if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
	{
		checko++;
	}
	else if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
	{
		checko++;
	}

	else if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
	{
		checko++;
	}
	else if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
	{
		checko++;
	}
	else if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
	{
		checko++;
	}

	else if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
	{
		checko++;
	}
	else if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O')
	{
		checko++;
	}

	if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
	{
		checkx++;

	}
	else if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
	{
		checkx++;
	}
	else if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
	{
		checkx++;
	}

	else if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
	{
		checkx++;
	}
	else if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
	{
		checkx++;
	}
	else if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
	{
		checkx++;
	}

	else if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
	{
		checkx++;
	}
	else if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')
	{
		checkx++;
	}


	if (checkx > 0)
	{
		Draw();
		cout << "Player X wins, COGRATULATIONS.";
		play_again();
	}
	else if (checko > 0)
	{
		Draw();
		cout << "Player O wins, COGRATULATIONS.";
		play_again();
	}
}
int main()
{
	choose();
	while (1)
	{
		Draw();
		input();
		win();
		tie();
	}
	return 0;
}
