#include <iostream>
#include <vector>
#include "stdio.h"

using namespace std;

int main()
{
	int squares[10000];
	for (int i = 0; i < 10000; i++)
		squares[i] = i*i;

	int digits;
	while (cin >> digits)
	{
		if (digits != 2 && digits != 4 && digits != 6 && digits != 8)
			return 0;

		int limit;
		int factor;
		switch(digits)
		{
		case 2: limit = 100; factor = 10; break;
		case 4: limit = 10000; factor = 100; break;
		case 6: limit = 1000000; factor = 1000; break;
		case 8: limit = 100000000; factor = 10000; break;
		}

		int index = 0;
		while (squares[index] < limit && index < 10000)
		{
			int temp = squares[index];
			int left; int right;
			left = temp / factor;
			right = temp % factor;
			int sum = left + right;
			if (sum*sum == temp)
			{
				switch(digits)
				{
				case 2: 
					printf("%02d\n", temp);
					break;
				case 4:
					printf("%04d\n", temp);
					break;
				case 6: 
					printf("%06d\n", temp);
					break;
				case 8:
					printf("%08d\n", temp);
					break;
				}
			}
			index++;
		}
	}
	return 0;
}