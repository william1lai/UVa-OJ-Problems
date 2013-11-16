#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

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

bool charcomp(char c, char d)
{
	bool cupper = isupper(c);
	bool dupper = isupper(d);

	if (cupper == dupper)
		return (c - d < 0);

	if (cupper)
	{
		int diff = (c - 'A') - (d - 'a');
		if (diff <= 0)
			return true;
		else
			return false;
	}
	if (dupper)
	{
		int diff = (c - 'a') - (d - 'A');
		if (diff < 0)
			return true;
		else
			return false;
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

		sort(lets.begin(), lets.end(), charcomp);

		printPerms("", lets);
	}
	return 0;
}