#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long n;
	while (cin >> n)
	{
		if (n < 0)
			return 0;

		if (n == 1)
			cout << "0%\n";
		else
		{
			long long ans = 25*n; //n pi r^2 / 4 pi r^2
			cout << ans << "%\n";
		}
	}
	return 0;
}