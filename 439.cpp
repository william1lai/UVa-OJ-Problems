#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

struct Square
{
	int column;
	int row;
};

int getJumps(Square f, Square s)
{
	int board[9][9];
	for (int i = 0; i < 9; i++)
	for (int j = 0; j < 9; j++)
	{
		board[i][j] = -1;
	}
	board[f.row][f.column] = 0;
	queue<Square> sq;
	sq.push(f);

	while (!sq.empty()) //do breadth-first search
	{
		f = sq.front();
		sq.pop();
		int jumpsAlready = board[f.row][f.column];
		if (f.column == s.column && f.row == s.row)
			return jumpsAlready;

	
		if (f.row - 2 >= 1)
		{
			if (f.column - 1 >= 1)
			{
				if (board[f.row - 2][f.column - 1] == -1) //not already processed
				{
					board[f.row - 2][f.column - 1] = jumpsAlready + 1;
					Square temp;
					temp.row = f.row - 2;
					temp.column = f.column - 1;
					sq.push(temp);
				}
			}
			if (f.column + 1 <= 8)
			{
				if (board[f.row - 2][f.column + 1] == -1)
				{
					board[f.row - 2][f.column + 1] = jumpsAlready + 1;
					Square temp;
					temp.row = f.row - 2;
					temp.column = f.column + 1;
					sq.push(temp);
				}
			}
		}
		if (f.row - 1 >= 1)
		{
			if (f.column - 2 >= 1)
			{
				if (board[f.row - 1][f.column - 2] == -1)
				{
					board[f.row - 1][f.column - 2] = jumpsAlready + 1;
					Square temp;
					temp.row = f.row - 1;
					temp.column = f.column - 2;
					sq.push(temp);
				}
			}
			if (f.column + 2 <= 8)
			{
				if (board[f.row - 1][f.column + 2] == -1)
				{
					board[f.row - 1][f.column + 2] = jumpsAlready + 1;
					Square temp;
					temp.row = f.row - 1;
					temp.column = f.column + 2;
					sq.push(temp);
				}
			}
		}
		if (f.row + 1 <= 8)
		{
			if (f.column - 2 >= 1)
			{
				if (board[f.row + 1][f.column - 2] == -1)
				{
					board[f.row + 1][f.column - 2] = jumpsAlready + 1;
					Square temp;
					temp.row = f.row + 1;
					temp.column = f.column - 2;
					sq.push(temp);
				}
			}
			if (f.column + 2 <= 8)
			{
				if (board[f.row + 1][f.column + 2] == -1)
				{
					board[f.row + 1][f.column + 2] = jumpsAlready + 1;
					Square temp;
					temp.row = f.row + 1;
					temp.column = f.column + 2;
					sq.push(temp);
				}
			}
		}
		if (f.row + 2 <= 8)
		{
			if (f.column - 1 >= 1)
			{
				if (board[f.row + 2][f.column - 1] == -1)
				{
					board[f.row + 2][f.column - 1] = jumpsAlready + 1;
					Square temp;
					temp.row = f.row + 2;
					temp.column = f.column - 1;
					sq.push(temp);
				}
			}
			if (f.column + 1 <= 8)
			{
				if (board[f.row + 2][f.column + 1] == -1)
				{
					board[f.row + 2][f.column + 1] = jumpsAlready + 1;
					Square temp;
					temp.row = f.row + 2;
					temp.column = f.column + 1;
					sq.push(temp);
				}
			}
		}
	}
	return -1; //error
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		istringstream iss(line);
		string first;
		string second;
		iss >> first >> second;

		Square f;
		f.column = first[0] - 'a' + 1;
		f.row = first[1] - '0';

		Square s;
		s.column = second[0] - 'a' + 1;
		s.row = second[1] - '0';

		cout << "To get from " << first << " to " << second << " takes " << getJumps(f, s) << " knight moves.\n";
	}
	return 0;
}
		