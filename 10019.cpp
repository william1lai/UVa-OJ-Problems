#include <iostream>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;

	for (int i = 0; i < ncases; i++)
	{
		int num;
		cin >> num;

		int temp = num;
		int b1 = 0;
		while (temp > 0)
		{
			b1 = b1 + (temp % 2);
			temp = temp / 2;
		}

		int b2 = 0;
		while (num > 0)
		{
			temp = num % 10;
			num = num / 10;

			while (temp > 0)
			{
				b2 = b2 + (temp % 2);
				temp = temp / 2;
			}
		}

		cout << b1 << " " << b2 << endl;
	}
	return 0;
}