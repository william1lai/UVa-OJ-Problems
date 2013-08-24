#include <iostream>

using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		int digits = 1;
		int one = 1;
		while (one % num != 0)
		{
			one = ((one % num) * 10) + 1;
			digits++;
		}

		cout << digits << endl;
	}
	return 0;
}
