#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void printPerms(string already, string left)
{
	if (left == "")
	{
		cout << already << "\n";
		return;
	}

	for (int i = 0; i < left.length(); i++)
	{
		char c = left[i];
		if (i > 0 && left[i] == left[i-1])
			continue;

		string atemp = already + c;
		string ltemp = left.substr(0, i) + left.substr(i + 1, left.length() - i);
		printPerms(atemp, ltemp);
	}
}

int main()
{
	int nstrs;
	cin >> nstrs;
	cin.ignore(1000, '\n');

	for (int i = 0; i < nstrs; i++)
	{
		string lets;
		getline(cin, lets);

		sort(lets.begin(), lets.end());

		printPerms("", lets);
		cout << "\n";
	}
	return 0;
}