#include <iostream>
#include "stdio.h"

using namespace std;

int main()
{
	int casecount = 1;
	long long num;
	long long limit;
	cin >> num >> limit;

	while (num > 0 && limit > 0)
	{
		int count = 0;
		long long temp = num;

		while (temp <= limit)
		{
			count++;
			if (temp == 1) break;
			else if (temp % 2 == 0) temp = temp / 2;
			else temp = (3*temp) + 1;
		}

		printf("Case %d: A = %d, limit = %d, number of terms = %d\n", casecount, num, limit, count);
		casecount++;
		cin >> num >> limit;
	}

	return 0;
}