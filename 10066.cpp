#include <iostream>

using namespace std;

int main()
{
	int n1;
	int n2;
	int caseno = 0;
	//bool first = true;
	while (cin >> n1 >> n2)
	{
		if (n1 == 0)
			return 0;

		/*
		if (first)
			first = false;
		else
			cout << "\n";
		*/

		caseno++;
		int* tiles = new int[n1];
		int* dp = new int[n1];

		for (int i = 0; i < n1; -i++)
		{
			cin >> tiles[i];
			dp[i] = 0;
		}

		for (int i = 0; i < n2; i++)
		{
			int n;
			cin >> n;

			int max = 0;
			for (int j = 0; j < n1; j++)
			{
				int tmax = max;
				if (dp[j] > max)
					max = dp[j];
				if (tiles[j] == n)
					dp[j] = tmax + 1;
			}
		}

		int max = 0;
		for (int i = 0; i < n1; i++)
		{
			if (dp[i] > max)
			max = dp[i];
		}

		cout << "Twin Towers #" << caseno << "\n";
		cout << "Number of Tiles : " << max << "\n\n";
	}
	return 0;
}