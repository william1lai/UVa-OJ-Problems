#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> pikachu;

	int temp;
	while (cin >> temp)
	{
		pikachu.push_back(temp);
		sort(pikachu.begin(), pikachu.end());

		int len = pikachu.size();
		if (len % 2 == 0)
		{
			cout << (pikachu[len/2] + pikachu[len/2 - 1]) / 2 << endl;
		}
		else
		{
			cout << (pikachu[len/2]) << endl;
		}
	}

	return 0;
}