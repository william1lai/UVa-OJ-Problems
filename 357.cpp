#include <iostream>

using namespace std;

int main()
{
	long long ways[30001];
	
	ways[0] = 1;
	for (int i = 1; i <= 30000; i++)
		ways[i] = 0;

	//halfdollars
	for (int i = 0; i <= 29950; i++)
		ways[i+50] = ways[i+50] + ways[i];

	//quarters
	for (int i = 0; i <= 29975; i++)
		ways[i+25] = ways[i+25] + ways[i];

	//dimes
	for (int i = 0; i <= 29990; i++)
		ways[i+10] = ways[i+10] + ways[i];

	//nickels
	for (int i = 0; i <= 29995; i++)
		ways[i+5] = ways[i+5] + ways[i];

	//pennies
	for (int i = 0; i <= 29999; i++)
		ways[i+1] = ways[i+1] + ways[i];

	int n;
	while (cin >> n)
	{
		long long ans = ways[n];
		if (ans == 1)
			cout << "There is only 1 way to produce " << n << " cents change.\n";
		else
			cout << "There are " << ans << " ways to produce " << n << " cents change.\n";
	}
	return 0;
}