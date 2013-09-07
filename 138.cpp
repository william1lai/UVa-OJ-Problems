#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int linesPrinted = 0;
	long long num = 6;
	long long sum = 15;
	long long temp = num + 1;
	long long tempSum = temp;

	while (linesPrinted < 10)
	{
		while (tempSum < sum)
		{
			temp++;
			tempSum = tempSum + temp;
			
			if (tempSum == sum)
			{
				printf("%10d", num);
				printf("%10d\n", temp);
				linesPrinted++;
			}
		}

		sum = sum + num;
		num++;
		tempSum = tempSum - num;
	}
	return 0;
}