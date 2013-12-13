#include <iostream>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;

	for (int i = 0; i < ncases; i++)
	{
		long long first;
		long long second;
		cin >> first >> second;

		long long diff = second - first;
		int steps = 0;
		int stride = 0;

		while (diff > 0)
		{
			int lgstride = stride + 1;
			int shtstride = stride - 1;

			if (lgstride*(lgstride + 1)/2 <= diff)
			{
				stride = lgstride;
			}
			else if (stride*(stride + 1)/2 > diff)
			{
				stride = shtstride;
			}

			diff = diff - stride;
			steps++;
		}

		cout << steps << "\n";
	}
	return 0;
}