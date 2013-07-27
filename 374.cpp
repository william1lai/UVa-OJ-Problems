#include <iostream>
#include <climits>

using namespace std;

int main()
{
	long long base;
	int power;
	int mod;
	while (cin >> base >> power >> mod)
	{
		long long result = 1;
		base = base % mod;
		while (power > 0)
		{
			if (power % 2 == 0)
			{
				power = power / 2;
				base = (base * base) % mod;
			}
			else
			{
				result = (result * base) % mod;
				power = power - 1;
			}
		}
		cout << result << endl;
	}

	return 0;
}