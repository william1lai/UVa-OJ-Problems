#include <iostream>

using namespace std;

int main()
{
	int rows;
	int columns;

	while (cin >> rows >> columns)
	{
		cout << (rows * columns) - 1 << endl;
	}

	return 0;
}