#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
	bool isPrime[46341];
	for (int i = 0; i < 46341; i++)
		isPrime[i] = true;

	for (int i = 2; i < 46341; i++)
	{
		if (isPrime[i])
		{
			for (int j = i*i; j < 46341; j = j + i)
				isPrime[j] = false;
		}
	}

	int num;
	while (cin >> num)
	{
		if (num == 0)
			return 0;

		cout << num << " = ";
		if (num < 0)
		{
			cout << "-1 x ";
			num = -num;
		}

		for (int i = 2; i < 46341; i++)
		{
			if (num < 46341 && isPrime[num])
				break;

			if (isPrime[i])
			{
				while (num % i == 0 && (num > 46341 || !isPrime[num]))
				{
					num = num / i;
					cout << i << " x ";
				}
			}
		}
		cout << num << endl;
	}
	return 0;
}