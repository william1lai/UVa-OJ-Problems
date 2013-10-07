#include <iostream>

using namespace std;

int main()
{
	bool isPrime[1000000];
	for (int i = 2; i < 1000000; i++)
		isPrime[i] = true;

	for (int i = 2; i < 1000; i++)
	{
		for (int j = i*i; j < 1000000; j = j + i)
			isPrime[j] = false;
	}

	int num;
	while (cin >> num)
	{
		if (isPrime[num])
		{
			int backwards = 0;
			int temp = num;
			while (temp > 0)
			{
				backwards = (backwards*10) + temp % 10;
				temp = temp / 10;
			}
			
			if (isPrime[backwards] && backwards != num)
			{
				cout << num << " is emirp.\n";
			}
			else
			{
				cout << num << " is prime.\n";
			}
		}
		else
		{
			cout << num << " is not prime.\n";
		}
	}
	return 0;
}