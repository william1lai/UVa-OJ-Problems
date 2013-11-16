#include <iostream>

using namespace std;

int main()
{
	int numer;
	int denom;
	while (cin >> numer >> denom)
	{
		cout << "[" << (numer / denom);

		int temp = numer % denom;
		numer = denom;
		denom = temp;

		bool firstterm = true;
		while (temp > 0)
		{
			if (firstterm)
			{
				cout << ";";
				firstterm = false;
			}
			else
				cout << ",";

			cout << (numer / denom);
			temp = numer % denom;
			numer = denom;
			denom = temp;
		}
		cout << "]\n";
	}
	return 0;
}