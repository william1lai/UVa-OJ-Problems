#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> squares;
	for (int i = 1; i <= 1000; i++)
		squares.push_back(i*i);

	int a;
	int b;
	while (cin >> a >> b)
	{
		if (a == 0)
			return 0;

		int f = lower_bound(squares.begin(), squares.end(), a) - squares.begin();
		int s = lower_bound(squares.begin(), squares.end(), b + 1) - squares.begin();

		cout << (s - f) << "\n";
	}
	return 0;
}