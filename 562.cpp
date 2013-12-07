#include <iostream>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;

	for (int i = 0; i < ncases; i++)
	{
		int ncoins;
		cin >> ncoins;

		if (ncoins <= 0)
		{
			cout << "0\n";
			continue;
		}

		int* coins = new int[ncoins];
		int sum = 0;
		for (int j = 0; j < ncoins; j++)
		{
			cin >> coins[j];
			sum = sum + coins[j];
		}

		bool** dp = new bool*[ncoins];
		for (int r = 0; r < ncoins; r++)
		{
			dp[r] = new bool[sum / 2 + 1];
			dp[r][0] = true;
			for (int c = 1; c <= sum / 2; c++)
				dp[r][c] = false;
		}

		for (int r = 0; r < ncoins; r++)
		{
			int coin = coins[r];
			for (int c = sum / 2; c >= 0; c--)
			{
				if (r == 0 && coin <= sum / 2)
					dp[0][coin] = true;

				if (r > 0)
				{
					if (c >= coin)
						dp[r][c] = dp[r][c] | dp[r-1][c-coin];
					dp[r][c] = dp[r][c] | dp[r-1][c];
				}
			}
		}

		int pikachu = sum / 2;
		while (dp[ncoins - 1][pikachu] == false)
		{
			pikachu--;
		}

		cout << (sum - 2*pikachu) << "\n";
	}
	return 0;
}