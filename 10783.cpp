#include <iostream>

using namespace std;

int main()
{
	int ncases;
	int casenum = 0;
	int first;
	int last;

	cin >> ncases;

	int i;
	for (i = 0; i < ncases; i++)
	{
		casenum++;
		cin >> first >> last;
		if (last % 2 == 0) last--;
		if (first % 2 == 0) first++;
		int numOfNums = ((last - first) / 2) + 1;
		int result = ((first + last)*numOfNums) / 2;
		cout << "Case " << casenum << ": " << result << endl;
	}

	return 0;
}