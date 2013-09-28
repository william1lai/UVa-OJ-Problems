#include <iostream>

using namespace std;

int main()
{
	long long low;
	long long high;
	while (cin >> low >> high)
	{
		if (low == 0 && high == 0)
			return 0;

		if (low > high)
		{
			int t = low;
			low = high;
			high = t;
		}

		long long max = 0;
		long long maxIndex = -1;
		for (long long i = low; i <= high; i++)
		{
			int count = 1;
			long long temp = i;
			if (temp % 2 == 0)
				temp = temp / 2;
			else
				temp = temp*3 + 1;

			while (temp != 1)
			{
				count++;
				if (temp % 2 == 0)
					temp = temp / 2;
				else
					temp = temp*3 + 1;
			}

			if (count > max)
			{
				max = count;
				maxIndex = i;
			}
		}

		cout << "Between " << low << " and " << high << ", " << maxIndex << " generates the longest sequence of " << max << " values.\n";
	}

	return 0;
}