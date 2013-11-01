#include <iostream>

using namespace std;

int main()
{
	int ans[1001];
	ans[0] = 1;
	ans[1] = 1;

	long long running = 1;
	for (int i = 2; i < 1001; i++)
	{
		running = running*(long long)i;
		int sum = 0;
		long long temp = running;
		while (temp > 0)
		{
			sum = sum + temp % 10;
			temp = temp / 10;
		}
		ans[i] = sum;
	}

	int n;
	while (cin >> n)
	{
		cout << ans[n] << "\n";
	}
	return 0;
}