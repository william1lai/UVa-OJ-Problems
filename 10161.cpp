#include <iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			return 0;

		int root = 1;
		while (n >= root*root)
			root++;

		int lower = root - 1;
		int rootsq = root*root;
		int lowersq = lower*lower;

		if (lower % 2 == 0) //even
		{
			int diff = n - lowersq;
			if (diff == 0)
			{
				cout << lower << " " << 1 << endl;
			}
			else if (diff <= (rootsq - lowersq) / 2) //count up from edge
			{
				cout << root << " " << diff << endl;
			}
			else
			{
				cout << (rootsq - n) + 1 << " " << root << endl;
			}
		}
		else //odd
		{
			int diff = n - lowersq;
			if (diff == 0)
			{
				cout << 1 << " " << lower << endl;
			}
			else if (diff <= (rootsq - lowersq) / 2) //count right from edge
			{
				cout << diff << " " << root << endl;
			}
			else
			{
				cout << root << " " << (rootsq - n) + 1 << endl;
			}
		}
	}
	return 0;
}