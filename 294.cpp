#include <iostream>

using namespace std;

int main()
{
	long long nentries;
	cin >> nentries;
	
	for (long long i = 0; i < nentries; i++)
	{
		long long lower;
		long long upper;
		cin >> lower >> upper;

		long long mostDivisors = -1;
		long long mostDivIndex = -1;
		for (long long j = lower; j <= upper; j++)
		{
			long long divisors = 2;
			long long k;
			for (k = 2; k*k < j; k++)
			{
				if (j % k == 0)
					divisors = divisors + 2;
			}
			if (k*k == j) //square root only gives one divisor
				divisors++;
			if (j == 1)
				divisors = 1;
		
			if (divisors > mostDivisors)
			{
				mostDivisors = divisors;
				mostDivIndex = j;
			}
		}
		
		cout << "Between " << lower << " and " << upper
		     << ", " << mostDivIndex << " has a maximum of "
		     << mostDivisors << " divisors.\n";
	}
	return 0;
}