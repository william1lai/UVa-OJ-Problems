#include <iostream>

using namespace std;

int main()
{
	int dp[601];
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= 600; i++)
	{
		dp[i] = (i / 3) + dp[(i / 3) + (i % 3)];
	}

	int n;
	while (cin >> n)
	{
		cout << dp[n*3] << "\n";
	}
	return 0;
}