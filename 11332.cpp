#include <iostream>

using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		if (num == 0)
			return 0;

		while (num >= 10)
		{
			int temp = num;
			num = 0;
			while (temp > 0)
			{
				num = num + temp % 10;
				temp = temp / 10;
			}
		}
		cout << num << endl;
	}
	return 0;
}