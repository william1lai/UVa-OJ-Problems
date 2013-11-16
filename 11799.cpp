#include <iostream>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;
	cin.ignore(1000, '\n');

	for (int n = 1; n <= ncases; n++)
	{
		int max = 0;
		int temp;
		while (cin.peek() != '\n')
		{
			cin >> temp;
			if (temp > max)
				max = temp;
		}
		cin.ignore(1000, '\n');
		cout << "Case " << n << ": " << max << "\n";
	}
	return 0;
}