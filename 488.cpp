#include <iostream>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;

	int amp;
	int freq;

	for (int i = 0; i < ncases; i++)
	{
		cin >> amp >> freq;

		for (int f = 0; f < freq; f++)
		{
			for (int j = 1; j <= amp; j++)
			{
				for (int k = 0; k < j; k++)
					cout << j;
				cout << endl;
			}
			for (int j = amp - 1; j > 0; j--)
			{
				for (int k = 0; k < j; k++)
					cout << j;
				cout << endl;
			}
			if (f < freq - 1) cout << endl;
		}

		if (i < ncases - 1) cout << endl;
	}

	return 0;
}