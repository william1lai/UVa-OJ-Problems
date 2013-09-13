#include <iostream>

using namespace std;

int main()
{
	int N;
	int C;
	while (cin >> N >> C)
	{
		cout << N << " " << C << ":";

		bool* isPrime = new bool[N + 1];
		int numPrime = N;
		for (int i = 0; i < N + 1; i++)
			isPrime[i] = true;
		for (int i = 2; i*i <= N; i++)
		{
			if (isPrime[i])
			{
				for (int j = i*i; j <= N; j = j + i)
				{
					if (isPrime[j])
						numPrime = numPrime - 1;
					isPrime[j] = false;
				}
			}					
		}

		int skip;
		int entries;
		if (numPrime % 2 == 0)
		{
			skip = (numPrime / 2) - C;
			entries = 2*C;
		}
		else //numPrime % 2 == 1
		{		
			skip = (numPrime / 2) - C + 1;
			entries = 2*C - 1;
		}

		if (skip < 0)
			skip = 0;

		for (int i = 1; i <= N; i++)
		{
			if (isPrime[i])
			{
				if (skip > 0)
					skip = skip - 1;
				else
				{
					cout << " " << i;
					entries = entries - 1;
				}
				if (entries == 0)
					break;
			}
		}
		cout << endl << endl;
	}
	return 0;
}