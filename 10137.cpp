#include <iostream>
#include <algorithm>
#include "stdio.h"

using namespace std;

int main()
{
	int numKids;
	while (cin >> numKids)
	{
		if (numKids == 0)
			return 0;

		int* centExpenses = new int[numKids];
		int centSum = 0;
		int firsthalf;
		int secondhalf;
		for (int i = 0; i < numKids; i++)
		{
			cin >> firsthalf;
			cin.ignore(1);
			cin >> secondhalf;
			centExpenses[i] = firsthalf * 100 + secondhalf;
			centSum = centSum + centExpenses[i];
		}
		int centAverage = centSum / numKids;

		sort(centExpenses, centExpenses + numKids);

		int under = 0;
		int over = 0;
		int* distributedExpenses = new int[numKids];
		int i;
		for (i = 0; i < numKids; i++)
		{
			if (centExpenses[i] >= centAverage)
			{
				while (centExpenses[i] == centAverage)
				{
					i++;
				}
				break;
			}
			under = under + (centAverage - centExpenses[i]);
		}
		for ( ; i < numKids; i++)
		{
			over = over + (centExpenses[i] - centAverage - 1);
		}

		int change;
		if (over < under)
			change = under;
		else if (over > under)
			change = over;		
		else
			change = over;

		
		cout << "$" << change / 100 << ".";
		printf("%02d\n", change % 100);
	}
	return 0;
}