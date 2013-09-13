#include <iostream>

using namespace std;

int main()
{
	int nlines;
	int caseno = 1;
	cin >> nlines;
	for (int i = 0; i < nlines; i++)
	{
		cout << "Case " << caseno << ": ";

		int first;
		int second;
		int third;
		cin >> first >> second >> third;

		if (first > second)
		{
			if (third > first)
			{
				cout << first << endl;
			}
			else if (third > second)
			{
				cout << third << endl;
			}
			else
			{
				cout << second << endl;
			}
		}
		else
		{
			if (third > second)
			{
				cout << second << endl;
			}
			else if (third > first)
			{
				cout << third << endl;
			}
			else
			{
				cout << first << endl;
			}
		}
		caseno++;
	}
	return 0;
}