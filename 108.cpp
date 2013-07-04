#include <iostream>
#include "limits.h"

using namespace std;

int main()
{
	int dim;
	cin >> dim;
	int** arr;
	arr = new int*[dim];
	for (int i = 0; i < dim; i++)
	{
		arr[i] = new int[dim];
		for (int j = 0; j < dim; j++)
			cin >> arr[i][j];
	}

	int max = INT_MIN;
	int xMax1;
	int xMax2;
	int yMax1;
	int yMax2;

	int* tempPartials = new int[dim];



	for (int yBeg = 0; yBeg < dim; yBeg++)
	for (int xBeg = 0; xBeg < dim; xBeg++)
	{
		for (int i = 0; i < dim; i++)
			tempPartials[i] = 0;

		for (int y = yBeg; y < dim; y++)
		{
			int partialSum = 0;
			for (int x = xBeg; x < dim; x++)
			{
				partialSum += arr[y][x];
				tempPartials[x] += partialSum;

				if (tempPartials[x] > max)
				{
					max = tempPartials[x];
					xMax2 = x;
					yMax2 = y;
					xMax1 = xBeg;
					yMax1 = yBeg;
				}				
			}
		}
	}

	cout << max << endl;
}