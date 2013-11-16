#include <iostream>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;
	for (int i = 0; i < ncases; i++)
	{
		int n;
		int m;
		cin >> n >> m;
		int x = n - 2;
		int y = m - 2;

		int divx = x / 3;
		if (3*divx < x)
			divx++;
		int divy = y / 3;
		if (3*divy < y)
			divy++;

		cout << (divx*divy) << "\n";
	}
	return 0;
}