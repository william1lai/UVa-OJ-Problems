#include <iostream>
#include "stdio.h"
#include <string>

using namespace std;

bool fell(int xi, int yi, char dir, int dimx, int dimy)
{
	if (dir == 'N')
		return (yi >= dimy - 1);
	else if (dir == 'S')
		return (yi <= 0);
	else if (dir == 'W')
		return (xi <= 0);
	else //E
		return (xi >= dimx - 1);
}

char turnDir(char origDir, char command)
{
	if (command == 'F')
		return origDir;
	if (command == 'L')
	{
		if (origDir == 'N')
			return 'W';
		else if (origDir == 'S')
			return 'E';
		else if (origDir == 'W')
			return 'S';
		else
			return 'N';
	}
	else //R
	{
		if (origDir == 'N')
			return 'E';
		else if (origDir == 'S')
			return 'W';
		else if (origDir == 'W')
			return 'N';
		else
			return 'S';
	}
}

int main()
{
	int x;
	int y;
	cin >> x >> y;
	x++;
	y++;

	bool** fallen = new bool*[x];
	for (int i = 0; i < x; i++)
	{
		fallen[i] = new bool[y];
		for (int j = 0; j < y; j++)
			fallen[i][j] = false;
	}

	int xi;
	int yi;
	char dir;
	//while (scanf("%d %d %c\n", &xi, &yi, &dir))
	while (cin >> xi >> yi)
	{
		cin.get(dir);
		while (dir == ' ')
			cin.get(dir);
		cin.ignore(1000, '\n');
		string line;
		getline(cin, line);

		bool graceful = true;
		for (int i = 0; i < line.length(); i++)
		{
			char command = line[i];
			if (command == 'F')
			{
				if (fell(xi, yi, dir, x, y))
				{
					if (!fallen[xi][yi])
					{
						printf("%d %d %c LOST\n", xi, yi, dir);
						fallen[xi][yi] = true;
						graceful = false;
						break;
					}
					else
						continue;
				}
				else
				{
					if (dir == 'N')
						yi++;
					else if (dir == 'S')
						yi--;
					else if (dir == 'E')
						xi++;
					else
						xi--;
				}
			}
			else
			{
				dir = turnDir(dir, command);
			}
		}

		if (graceful)
			printf("%d %d %c\n", xi, yi, dir);
	}
	return 0;
}