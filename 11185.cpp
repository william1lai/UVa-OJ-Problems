#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n < 0)
			return 0;
		if (n == 0)
		{
			cout << "0\n";
			continue;
		}

		ostringstream oss;
		while (n > 0)
		{
			oss << (n % 3);
			n = n / 3;
		}

		string s = oss.str();
		for (int i = s.length() - 1; i >= 0; i--)
			cout << s[i];
		cout << "\n";
	}
	return 0;
}