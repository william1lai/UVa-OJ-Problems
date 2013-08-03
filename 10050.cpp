#include <iostream>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;

	for (int i = 0; i < ncases; i++)
	{
		int days;
		int parties;
		cin >> days >> parties;
	
		int* params = new int[parties];
		for (int j = 0; j < parties; j++)
			cin >> params[j];

		int hartals = 0;
		for (int j = 1; j <= days; j++)
		{
			if (j % 7 != 6 && j % 7 != 0)
			{
				for (int k = 0; k < parties; k++)
				{
					if (j % params[k] == 0)
					{
						hartals++;
						break;
					}
				}
			}
		}

		cout << hartals << endl;
	}

	return 0;
}