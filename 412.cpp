#include <iostream>
#include <vector>
#include <cmath>
#include "stdio.h"

using namespace std;

int gcf(int first, int second)
{
	while (first != 0 && second != 0)
	{
		if (first > second)
			first = first % second;
		else
			second = second % first;
	}
	if (second != 0)
		return second;
	else
		return first;
}

int main()
{
	int nnums;

	while (cin >> nnums)
	{
		if (nnums == 0)
			return 0;

		vector<int> nums;
		for (int i = 0; i < nnums; i++)
		{
			int temp;
			cin >> temp;
			nums.push_back(temp);
		}

		int hits = 0;
		int total = 0;
		for (int i = 0; i < nnums; i++)
		{
			for (int j = i + 1; j < nnums; j++)
			{
				total++;
				if (gcf(nums[i], nums[j]) == 1)
					hits++;
			}
		}

		if (hits == 0)
			cout << "No estimate for this data set.\n";
		else
		{
			double ans = sqrt(6.0*total / hits);
			printf("%f\n", ans);
		}
	}
	return 0;
}