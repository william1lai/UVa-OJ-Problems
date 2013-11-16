#include "stdio.h"
#include <vector>

using namespace std;

int main()
{
	int ncases;
	scanf("%d", &ncases);

	for (int i = 1; i <= ncases; i++)
	{
		int npillars;
		scanf("%d", &npillars);
		int high = 0;
		int low = 0;
		int temp;
		scanf("%d", &temp);
		for (int j = 0; j < npillars - 1; j++)
		{
			int tt;
			scanf("%d", &tt);
			if (tt > temp)
				high++;
			else if (tt < temp)
				low++;
			temp = tt;
		}
		printf("Case %d: %d %d\n", i, high, low);
	}
	return 0;
}