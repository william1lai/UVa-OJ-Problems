#include <iostream>

using namespace std;


int main()
{
	unsigned long long n;
	while (cin >> n)
	{
		unsigned long long index = (n - 1)*(n/2)/2 + n - 1;
		unsigned long long num = (2*index) - 1;
		unsigned long long ans = 3*num;

		cout << ans << endl;
	}

	return 0;
}