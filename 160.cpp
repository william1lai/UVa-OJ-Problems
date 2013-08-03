#include <iostream>
#include "stdio.h"
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int num;	
	cin >> num;
	while (num > 0)
	{
		int* factors = new int[25];
		memset(factors, 0, 25*sizeof(int));
		printf("%3d! =", num);

		for (int i = num; i >= 2; i--)
		{
			int temp = i;
			for (int k = 2; k <= i; k++)
			{
				int j = 0;
				while (temp % k == 0 && temp > 0)
				{
					j++;
					temp = temp / k;
				}

				switch (k)
				{
				case 2: factors[0] = factors[0] + j; break;
				case 3: factors[1] = factors[1] + j; break;
				case 5: factors[2] = factors[2] + j; break;
				case 7: factors[3] = factors[3] + j; break;
				case 11: factors[4] = factors[4] + j; break;
				case 13: factors[5] = factors[5] + j; break;
				case 17: factors[6] = factors[6] + j; break;
				case 19: factors[7] = factors[7] + j; break;
				case 23: factors[8] = factors[8] + j; break;
				case 29: factors[9] = factors[9] + j; break;
				case 31: factors[10] = factors[10] + j; break;
				case 37: factors[11] = factors[11] + j; break;
				case 41: factors[12] = factors[12] + j; break;
				case 43: factors[13] = factors[13] + j; break;
				case 47: factors[14] = factors[14] + j; break;
				case 53: factors[15] = factors[15] + j; break;
				case 59: factors[16] = factors[16] + j; break;
				case 61: factors[17] = factors[17] + j; break;
				case 67: factors[18] = factors[18] + j; break;
				case 71: factors[19] = factors[19] + j; break;
				case 73: factors[20] = factors[20] + j; break;
				case 79: factors[21] = factors[21] + j; break;
				case 83: factors[22] = factors[22] + j; break;
				case 89: factors[23] = factors[23] + j; break;
				case 97: factors[24] = factors[24] + j; break;
				default: break;
				}
			}
		}
		
		for (int k = 0; k < 25; k++)
		{
			if (factors[k] == 0) break;

			if (k == 15)
				printf("\n      %3d", factors[k]);
			else
				printf("%3d", factors[k]);
		}

		cout << endl;

		cin >> num;
	}

	return 0;
}