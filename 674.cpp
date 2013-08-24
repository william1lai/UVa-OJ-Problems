#include <iostream>

using namespace std;

int numWays[7490];

int main()
{
	for (int i = 0; i < 7490; i++)
		numWays[i] = 1;

	//this works because you only count each addition once
	//Rule: only add coin if no other coins of higher value are in set
	for (int j = 5; j < 7490; j++)
		numWays[j] += numWays[j-5];
	for (int k = 10; k < 7490; k++)
		numWays[k] += numWays[k-10];
	for (int m = 25; m < 7490; m++)
		numWays[m] += numWays[m-25];
	for (int n = 50; n < 7490; n++)
		numWays[n] += numWays[n-50];

	int num;
	while (cin >> num)
	{
		cout << numWays[num] << endl;
	}
	return 0;
}