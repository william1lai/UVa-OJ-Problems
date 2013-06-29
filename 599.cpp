#include <iostream>

using namespace std;

int main()
{
	int numCols;
	int* wall;
	int setCount = 0;
	cin >> numCols;

	while (numCols > 0)
	{
		setCount++;
		wall = new int[numCols];
		int i;
		int sum = 0;
		for (i = 0; i < numCols; i++)
		{
			cin >> wall[i];
			sum = sum + wall[i];
		}
		int avg = sum / numCols;

		int moves = 0;
		for (i = 0; i < numCols; i++)
		{
			int diff = wall[i] - avg;
			if (diff > 0)
				moves = moves + diff;
		}

		cout << "Set #" << setCount << endl;
		cout << "The minimum number of moves is " << moves << ".\n\n";
		cin >> numCols;
	}
}