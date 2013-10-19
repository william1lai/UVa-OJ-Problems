#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n1;
	int n2;
	int caseno = 0;
	bool first = true;
	while (cin >> n1 >> n2)
	{
		if (n1 == 0)
			return 0;

		if (first)
			first = false;
		else
			cout << "\n";

		caseno++;
		
		int* nums = new int[n1 + n2];
		for (int i = 0; i < n1 + n2; i++)
			cin >> nums[i];

		sort(nums, nums + n1 + n2);

		int index = 0;
		int height = 0;
		while (index < n1 + n2 - 1)
		{
			if (nums[index] == nums[index + 1])
			{
				height++;
				index = index + 2;
			}
			else
			{
				index++;
			}
		}

		cout << "Twin Towers #" << caseno << "\n";
		cout << "Number of Tiles : " << height << "\n";
	}
	return 0;
}