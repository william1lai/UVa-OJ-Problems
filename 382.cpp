#include <iostream>
#include "stdio.h"

using namespace std;

int main()
{
	int num;
	cin >> num;

	cout << "PERFECTION OUTPUT" << endl;
	while (num > 0)
	{
		if (num == 1)
		{
			cout << "    1  DEFICIENT" << endl;
			cin >> num;
			continue;
		}
		int factorSum = 1;
		for (int i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				factorSum = factorSum + i;
			}
			if (factorSum > num)
			{
				break;
			}
		}
		printf("%5d  ", num);
		if (factorSum > num)
			cout << "ABUNDANT" << endl;
		else if (factorSum < num)
			cout << "DEFICIENT" << endl;
		else
			cout << "PERFECT" << endl;		

		cin >> num;
	}
	cout << "END OF OUTPUT" << endl;

	return 0;
}