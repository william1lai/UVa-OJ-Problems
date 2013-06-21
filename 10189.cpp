#include <iostream>

using namespace std;

int countMines(char** field, int r, int c, int numRows, int numCols)
{
	int mineCount = 0;
	if (r > 0)
	{
		if (c > 0)
		{
			if (field[r-1][c-1] == '*') mineCount++;
		}
		if (c < numCols - 1)
		{
			if (field[r-1][c+1] == '*') mineCount++;
		}
		if (field[r-1][c] == '*') mineCount++;
	}
	if (r < numRows - 1)
	{
		if (c > 0)
		{
			if (field[r+1][c-1] == '*') mineCount++;
		}
		if (c < numCols - 1)
		{
			if (field[r+1][c+1] == '*') mineCount++;
		}
		if (field[r+1][c] == '*') mineCount++;
	}
	if (c > 0 && field[r][c-1] == '*') mineCount++;
	if (c < numCols - 1 && field[r][c+1] == '*') mineCount++;

	return mineCount;
} 

int main()
{
	int fieldNum = 0;
	int numRows;
	int numCols;
	char** field;

	cin >> numRows >> numCols;
	while (numRows != 0 && numCols != 0)
	{
		if (fieldNum != 0)
			cout << endl;

		fieldNum = fieldNum + 1;
		field = new char*[numRows];
		int i;
		int j;
		for (i = 0; i < numRows; i++)
		{
			field[i] = new char[numCols];

			for (j = 0; j < numCols; j++)
			{
				cin >> field[i][j];
			}
		}

		//now we count mines
		cout << "Field #" << fieldNum << ":\n";
		for (i = 0; i < numRows; i++)
		{
			for (j = 0; j < numCols; j++)
			{
				if (field[i][j] == '*')
					cout << '*';
				else
					cout << countMines(field, i, j, numRows, numCols);
			}
			cout << endl;
		}
		cin >> numRows >> numCols;
	}
	return 0;
}