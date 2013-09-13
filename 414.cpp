#include <iostream>
#include <string>

using namespace std;

int main()
{
	int nlines;
	while (cin >> nlines)
	{
		if (nlines == 0)
			return 0;

		cin.ignore(1000, '\n');
		string* data = new string[nlines];
		for (int i = 0; i < nlines; i++)
			getline(cin, data[i]);

		int totalBlanks = 0;
		int fewestBlanks = data[0].length();
		for (int i = 0; i < nlines; i++)
		{
			string cur = data[i];
			int numBlanks = 0;
			for (int j = 0; j < cur.length(); j++)
			{
				if (cur[j] == ' ')
					numBlanks++;
			}
			totalBlanks = totalBlanks + numBlanks;
			if (numBlanks < fewestBlanks)
				fewestBlanks = numBlanks;
		}

		cout << (totalBlanks - (fewestBlanks * nlines)) << endl;
	}
	return 0;
}