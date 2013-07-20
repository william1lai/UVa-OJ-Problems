#include <iostream>
#include <algorithm>

using namespace std;

int compare(const void* first, const void* second)
{
	return (*(int*)first - *(int*)second);
}

int main()
{
	int ncases;
	cin >> ncases;

	for (int i = 0; i < ncases; i++)
	{
		int relatives;
		cin >> relatives;
		int* addresses = new int[relatives];
		for (int j = 0; j < relatives; j++)
			cin >> addresses[j];

		qsort(addresses, relatives, sizeof(int), compare);

		int minDist = 0;
		for (int k = 0; k < relatives / 2; k++)
		{
			int edgeDiff = addresses[relatives - k - 1] - addresses[k];
			minDist = minDist + edgeDiff;
		}

		cout << minDist << endl;
	}

	return 0;
}