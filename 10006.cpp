#include <iostream>

using namespace std;

bool isPrime[65001];

bool passesFermat(long long num)
{
	for (long long i = 2; i < num; i++)
	{
		long long a = i;
		long long n = num;
		long long product = 1;
		while (n > 1)
		{
			if (n % 2 == 0)
			{
				a = (a*a) % num;
				n = n / 2;
			}
			else
			{
				product = (product * a) % num;
				n = n - 1;
			}
		}
		product = (product * a) % num;
		if (product != i)
			return false;
	}
	return true;
}

int main()
{
	for (int i = 2; i <= 65000; i++)
		isPrime[i] = true;
	for (int i = 2; i <= 255; i++)
	{
		for (int j = i*i; j <= 65000; j = j + i)
			isPrime[j] = false;
	}

	long long num;
	while (cin >> num)
	{
		if (num == 0)
			break;
		if (!isPrime[num] && passesFermat(num))
		{
			cout << "The number " << num << " is a Carmichael number.\n";
		}
		else
		{
			cout << num << " is normal.\n";
		}
	}
	return 0;
}