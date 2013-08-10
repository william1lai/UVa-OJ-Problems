#include <iostream>
#include <cstring>

using namespace std;


int main()
{
	const int LIMIT = 1000000;
	bool primes[LIMIT];
	memset(primes, true, LIMIT*sizeof(bool));
	primes[0] = false; primes[1] = false;

	for (int i = 2; i < 1000; i++)
	{
		if (primes[i])
		{
			for (int j = i*i; j < LIMIT; j = j + i)
			{
				primes[j] = false;
			}
		}
	}

	int num;
	cin >> num;
	while (num > 0)
	{
		int temp = 3;
		bool gotResult = false;
		while (temp <= num / 2)
		{
			if (primes[temp] && primes[num - temp])
			{
				cout << num << " = " << temp << " + " << num - temp << endl;
				gotResult = true;
				break;
			}
			temp++;
		}

		if (!gotResult) cout << "Goldbach's conjecture is wrong." << endl;

		cin >> num;
	}

	return 0;
}