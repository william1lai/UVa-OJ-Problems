#include <iostream>

using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		if (num == 0)
			return 0;

		int I = 0;
		int V = 0;
		int X = 0;
		int L = 0;
		int C = 0;

		for (int i = 1; i <= num; i++)
		{		
			int onesDigit = i % 10;
			int tensDigit = i / 10;

			switch (onesDigit)
			{
			case 0: break;
			case 1:
			case 2:
			case 3:
				I = I + onesDigit;
				break;
			case 4:
				I = I + 1;
				V = V + 1;
				break;
			case 5:
			case 6:
			case 7:
			case 8:
				I = I + (onesDigit - 5);
				V = V + 1;
				break;
			case 9:
				I = I + 1;
				X = X + 1;
				break;
			}

			switch (tensDigit)
			{
			case 0: break;
			case 1:
			case 2:
			case 3:
				X = X + tensDigit;
				break;
			case 4:
				X = X + 1;
				L = L + 1;
				break;
			case 5:
			case 6:
			case 7:
			case 8:
				X = X + (tensDigit - 5);
				L = L + 1;
				break;
			case 9:
				X = X + 1;
				C = C + 1;
				break;
			}
		}
	
		cout << num << ": " << I << " i, " << V << " v, "
		     << X << " x, " << L << " l, " << C << " c\n";
	}
	return 0;
}