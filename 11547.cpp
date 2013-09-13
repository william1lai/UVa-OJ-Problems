#include <iostream>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;
	for (int i = 0; i < ncases; i++)
	{
		int n;
		cin >> n;
		int ans = ((n*315 + 36962) / 10) % 10;
		if (ans < 0)
			ans = -ans;
		cout << ans << endl;
	}
	return 0;
}