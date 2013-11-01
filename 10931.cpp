#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			return 0;

		int parity = 0;
		ostringstream oss;
		while (n > 0)
		{
			int bit = n % 2;
			parity = parity + bit;
			oss << bit;
			n = n >> 1;
		}

		string s = oss.str();
		ostringstream oss2;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			oss2 << s[i];
		}

		cout << "The parity of " << oss2.str() << " is " << parity << " (mod 2).\n";
	}
	return 0;
}
