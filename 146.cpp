#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		if (line == "#") break;

		int first = -1;
		int second = -1;

		for (int i = line.length() - 2; i >= 0; i--)
		{
			for (int j = i+1; j < line.length(); j++)
			{
				if (line[j] > line[i])
				{
					first = i;
					second = j;
				}
			}

			if (first >= 0 && second >= 0)
				break;
		}

		if (first >= 0 && second >= 0)
		{
			cout << line.substr(0, first) << line[second];
			string temp = line.substr(first, second-first) + line.substr(second+1, line.length()-second-1);
			sort(temp.begin(), temp.end());
			cout << temp << endl;
		}
		else cout << "No Successor" << endl;
	}

	return 0;
}