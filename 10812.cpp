#include <iostream>

using namespace std;

int main()
{
	int nlines;
	cin >> nlines;

	for (int i = 0; i < nlines; i++)
	{
		int sum;
		int diff;
		cin >> sum >> diff;

		if (diff > sum)
		{
			cout << "impossible" << endl;
			continue;
		}

		double high = (sum + diff) / 2.0;
		double low = (sum - diff) / 2.0;

		if ((high - int(high) != 0) || (low - int(low) != 0))
		{
			cout << "impossible" << endl;
			continue;
		}

		cout << high << " " << low << endl;
	}

	return 0;
}