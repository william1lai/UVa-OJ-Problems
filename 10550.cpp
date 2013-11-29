#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a;
	int b;
	int c;
	int d;

	while (cin >> a >> b >> c >> d)
	{
		if (a == 0 && b == 0 && c == 0 && d == 0)
			return 0;

		int ab = a - b;
		int bc = c - b;
		int cd = c - d;

		if (ab < 0)
			ab = ab + 40;
		if (bc < 0)
			bc = bc + 40;
		if (cd < 0)
			cd = cd + 40;

		int degs = 1080 + 9*(ab + bc + cd);

		cout << degs << "\n";
	}
	return 0;
}