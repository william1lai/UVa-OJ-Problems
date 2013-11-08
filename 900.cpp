#include <iostream>
#include "stdio.h"

using namespace std;

int main()
{
	int ans[51];
	ans[1] = 1;
	ans[2] = 2;
	for (int i = 3; i < 51; i++)
		ans[i] = ans[i-1] + ans[i-2];

	int n;
	while (cin >> n)
	{
		if (n == 0)
			return 0;

		printf("%d\n", ans[n]);
	}
	return 0;
}