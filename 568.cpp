#include <iostream>
#include "stdio.h"

using namespace std;

int main()
{
	int ans[10001];
	ans[0] = 1;

	for (int i = 1; i <= 10000; i++)
	{
		int temp = ans[i-1]*i;
		while (temp % 10 == 0)
		{
			temp = temp / 10;
		}
		ans[i] = temp % 100000;
	}

	int n;
	while (cin >> n)
	{
		printf("%5d -> %d\n", n, ans[n] % 10);
	}
	return 0;
}