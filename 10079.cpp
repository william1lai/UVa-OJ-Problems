#include <iostream>

using namespace std;

int main()
{
	long long numCuts;
	cin >> numCuts;

	while (numCuts >= 0)
	{
		cout << ((numCuts)*(numCuts + 1)/2) + 1 << endl;
		cin >> numCuts;
	}

	return 0;
}