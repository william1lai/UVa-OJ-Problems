#include <iostream>
#include <cstring>

using namespace std;

const int LIMIT = 32768;

int main()
{
	bool isPrime[LIMIT];
	memset(isPrime, true, LIMIT*sizeof(bool));
	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i < 256; i++)
	{
		if (isPrime[i])
		{
			for (int j = i*i; j < LIMIT; j += i)
				isPrime[j] = false;
		}
	}

	int num;
	cin >> num;
	while (num != 0)
	{
		int count = 0;
		for (int i = 2; i <= num / 2; i++)
		{
			if (isPrime[i] && isPrime[num - i])
				count++;
		}

		cout << count << endl;
		cin >> num;
	}

	return 0;
}