#include "pch.h"
#include<bits/stdc++.h>
using namespace std;

const int rows = 10;
const int columns = 10;
const int max_ships = 10;

int Matrix[rows][columns];

void clear()
{
	for (size_t x = 0; x < rows; x++)
	{
		for (size_t y = 0; y < columns; y++)
		{
			Matrix[x][y] = 0;
		}
	}
}
void setup()
{
	for (size_t i = 0; i < max_ships; i++)
	{
		int y = rand() % columns;
		int x = rand() % rows;
		if (Matrix[x][y] == 0)
		{
			Matrix[x][y] = 1;
		}
	}
}
void show()
{
	for (size_t x = 0; x < rows; x++)
	{
		for (size_t y = 0; y < columns; y++)
		{
			cout << Matrix[x][y] << " ";
		}
		cout << "\n";
	}
}
bool attack(int x, int y)
{
	return Matrix[x][y] == 1 ? true : false;
}

int main()
{
	srand(time(0));
	clear();
	setup();
	int x, y, ships = 0, trys = 10;
	cout << "-----------" << endl;
	cout << "This is a 10 by 10 map, try to locate the ships\n";
	cout << "You have " << trys << " trys" << endl;
	show();
	cout << "----------\n";
	while (1)
	{
		cout << "Hat coordinate: " << endl;
		cin >> x >> y;
		if (attack(x, y))
		{
			Matrix[1][1] = 2;
			ships++;
			if (ships == max_ships)
			{
				cout << "You Won congratulations\n";
				show();
				exit(0);
			}
			cout << "Bravo" << " reamning: " << max_ships - ships << endl;
		}
		else
		{
			trys--;
			cout << "HAHAHHAHA you missed, " << "Number of ships is: " << max_ships - ships << endl
				<< "\nYou have " << trys << " left" << endl;
			if (trys == 0)
			{
				cout << "Loooooooser\n";
				show();
				exit(0);
			}
		}
	}
	return 0;
}
