#include <iostream>
#include <cctype>
#include <string>

using namespace std;

void printNum(int digit, int size, int index, char** output)
{
	int cols = size + 2;
	int rows = 2*size + 3;
	int cindex = index*(cols+1);

	//first row
	if (digit != 1 && digit != 4)
	{
		for (int i = 1; i <= size; i++)
			output[0][cindex + i] = '-';
	}

	//middle row
	if (digit != 1 && digit != 7 && digit != 0)
	{
		for (int i = 1; i <= size; i++)
			output[rows/2][cindex + i] = '-';
	}

	//bottom row
	if (digit != 1 && digit != 4 && digit != 7)
	{
		for (int i = 1; i <= size; i++)
			output[rows-1][cindex + i] = '-';
	}

	//left top
	if (digit == 4 || digit == 5 || digit == 6 || digit == 8 || digit == 9 || digit == 0)
	{
		for (int r = 1; r <= size; r++)
			output[r][cindex] = '|';
	}

	//left bottom
	if (digit == 2 || digit == 6 || digit == 8 || digit == 0)
	{
		for (int r = rows/2 + 1; r < rows - 1; r++)
			output[r][cindex] = '|';
	}

	//right top
	if (digit != 5 && digit != 6)
	{
		for (int r = 1; r <= size; r++)
			output[r][cindex + size + 1] = '|';
	}

	//right bottom
	if (digit != 2)
	{
		for (int r = rows/2 + 1; r < rows - 1; r++)
			output[r][cindex + size + 1] = '|';
	}
}

int main()
{
	int size;
	string snum;
	cin >> size;
	getline(cin, snum);
	while (size != 0)
	{
		int digits = 0;
		int num = 0;
		int index = 0;
		while (index < snum.length())
		{
			if (isdigit(snum[index]))
			{
				num = num*10 + (snum[index] - '0');
				digits++;
			}
			index++;
		}

		int cols = size + 2;
		int rows = 2*size + 3;
		char** output = new char*[rows];
		for (int i = 0; i < rows; i++)
		{
			output[i] = new char[(cols+1)*digits]; //one for 0 bytes and blank spaces
			for (int j = 0; j < (cols+1)*digits; j++)
				output[i][j] = ' ';
			output[i][(cols+1)*digits - 1] = 0;
		}

		int temp = num;
		for (int index = digits-1; index >= 0; index--)
		{
			int val = temp % 10;
			temp = temp / 10;
			printNum(val, size, index, output);
		}

		for (int i = 0; i < rows; i++)
			cout << output[i] << endl;
		cout << endl;

		cin >> size;
		getline(cin, snum);
	}
	return 0;
}