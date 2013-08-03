#include <iostream>

using namespace std;

int main()
{
	int nums;
	while (cin >> nums)
	{
		int* arr = new int[nums];

		for (int i = 0; i < nums; i++)
		{
			cin >> arr[i];
		}

		int ops = 0;
		bool flipped = true;
		while (flipped)
		{
			flipped = false;
			for (int i = 0; i < nums - 1; i++)
			{
				if (arr[i] > arr[i+1])
				{
					int temp = arr[i+1];
					arr[i+1] = arr[i];
					arr[i] = temp;
					ops++;
					flipped = true;
				}
			}
		}

		cout << "Minimum exchange operations : " << ops << endl;
	}

	return 0;
}