#include <iostream>
#include "stdio.h"

using namespace std;

int main()
{
	int n;

	while (scanf("%d", &n))
	//while (cin >> n)
	{
		if (n == 0)
			return 0;

		int ages[100];
		for (int i = 0; i < 100; i++)
			ages[i] = 0;

		for (int i = 0; i < n; i++)
		{
			int temp;
			scanf("%d", &temp);
			//cin >> temp;
			ages[temp]++;
		}

		bool first = true;
		for (int i = 1; i < 100; i++)
		{
			int count = ages[i];
			if (count > 0)
			{
				for (int j = 0; j < count; j++)
				{
					if (first)
					{
						printf("%d", i);
						//cout << i;
						first = false;
					}
					else
					{
						printf(" %d", i);
						//cout << " " << i;
					}
				}
			}
		}
		printf("\n");
		//cout << endl;
	}
	return 0;
}