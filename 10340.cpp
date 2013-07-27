#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		istringstream iss(line);
		string first;
		string second;
		iss >> first >> second;

		int f = 0;
		for (int s = 0; s < second.length(); s++)
		{
			if (second[s] == first[f])
				f++;
		}

		if (f == first.length())
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}