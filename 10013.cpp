#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;

	for (int i = 0; i < ncases; i++)
	{
		if (i != 0)
			cout << "\n";

		int ndigits;
		cin >> ndigits;

		vector<int> num;
		num.push_back(0);

		for (int j = 1; j <= ndigits; j++)
		{
			int f;
			int s;
			cin >> f >> s;

			int sum = f + s;
			num.push_back(sum);
		}

		for (int j = ndigits; j >= 0; j--)
		{
			if (num[j] >= 10)
			{
				num[j - 1]++;
				num[j] = num[j] % 10;
			}
		}

		if (num[0] > 0)
			cout << num[0];

		for (int j = 1; j <= ndigits; j++)
			cout << num[j];
		cout << "\n";
	}
	return 0;
}