#include <iostream>
#include <climits>

using namespace std;

const int LIMIT = INT_MAX;
int memo[51][51];

int calculateMinimumCost(int* cuts, int start, int end, int woodStart, int woodEnd)
{
	if (memo[start][end] >= 0)
		return memo[start][end];

	if (start == end) return woodEnd - woodStart;

	int min = LIMIT;
	for (int i = start; i <= end; i++)
	{
		int temp = woodEnd - woodStart;

		if (i != start)
			temp = temp + calculateMinimumCost(cuts, start, i-1, woodStart, cuts[i]);

		if (i != end)
			temp = temp + calculateMinimumCost(cuts, i+1, end, cuts[i], woodEnd);
	
		if (temp < min)
			min = temp;
	}
	memo[start][end] = min; //memoize partial result
	return min;
}

int main()
{
	int woodLength;
	int nCuts;

	while (cin >> woodLength)
	{
		if (woodLength == 0)
			break;
		cin >> nCuts;
		int* cuts = new int[nCuts];
		for (int i = 0; i < nCuts; i++)
		{
			for (int j = 0; j < nCuts; j++)
				memo[i][j] = -1;
			cin >> cuts[i];
		}
		cout << "The minimum cutting is " << calculateMinimumCost(cuts, 0, nCuts-1, 0, woodLength) << ".\n";
	}
	return 0;
}