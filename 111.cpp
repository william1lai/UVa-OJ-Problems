#include <iostream>

using namespace std;

int LCS(int* order, int lowerBound, int index, int size, int length)
{
	if (index == size) return length;
	
	int next = order[index];

	if (next > lowerBound)
	{
		int take = LCS(order, next, index + 1, size, length + 1);
		int notake = LCS(order, lowerBound, index + 1, size, length);

		if (take > notake) return take;
		else return notake;
	}
	else
		return LCS(order, lowerBound, index + 1, size, length);
}

int main()
{
	int numEvents;
	cin >> numEvents;

	int* trueOrderMap = new int[numEvents + 1];
	for (int i = 1; i <= numEvents; i++)
		cin >> trueOrderMap[i];

	int nextEvent;
	while (cin >> nextEvent)
	{
		int* order = new int[numEvents + 1];
		order[nextEvent] = trueOrderMap[1];
		for (int i = 2; i <= numEvents; i++)
		{
			int temp;
			cin >> temp;
			order[temp] = trueOrderMap[i];
		}
		cout << LCS(order, 0, 1, numEvents + 1, 0) << endl;
	}
	return 0;
}