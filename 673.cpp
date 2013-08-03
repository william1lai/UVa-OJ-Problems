

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int nlines;
	cin >> nlines;
	cin.ignore(1000, '\n');

	for (int i = 0; i < nlines; i++)
	{
		string str;
		getline(cin, str);

		bool changed = true;
		while (changed == true && str.length() > 0)
		{
			changed = false;
			for (int j = 0; j < str.length() - 1; j++)
			{
				if (str[j] == '[' && str[j+1] == ']')
				{
					str = str.substr(0, j) + str.substr(j+2, str.length()-j-2);
					changed = true;
				}
				else if (str[j] == '(' && str[j+1] == ')')
				{
					str = str.substr(0, j) + str.substr(j+2, str.length()-j-2);
					changed = true;
				}

				if (str.length() == 0) break;
			}
		}
		if (str.length() == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}