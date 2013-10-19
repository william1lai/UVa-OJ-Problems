#include <iostream>

using namespace std;

int main()
{
	int ans[14];

	for (int k = 1; k < 14; k++)
	{
		int t = k;
		int nsize = 2*k;
		bool done = false;

		while (!done)
		{
			int carry = 1;
			t++;

			//an iteration of try
			int tsize = nsize;
			while (true)
			{
				int pos = (t - carry) % tsize;

				if (pos < k)
					break;
				else
				{
					carry = tsize - pos;
					tsize--;
					if (tsize == k)
					{
						done = true;
						break;
					}
				}
			}
		}

		ans[k] = t;
	}

	int n;
	while (cin >> n)
	{
		if (n == 0)
			return 0;

		cout << ans[n] << endl;
	}

	return 0;
}
					