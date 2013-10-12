#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	bool first = true;
	int ppl;
	while (cin >> ppl)
	{
		if (first)
			first = false;
		else
			cout << endl;

		string* names = new string[ppl];
		int* net = new int[ppl];

		cin.ignore(1000, '\n');
		for (int i = 0; i < ppl; i++)
		{
			string temp = "";
			char c;
			while (cin.get(c))
			{
				if (!isalpha(c))
					break;
				else
					temp = temp + c;
			}
			names[i] = temp;
			net[i] = 0;
		}

		for (int pikachu = 0; pikachu < ppl; pikachu++)
		{
			string temp = "";
			char c;
			while (cin.get(c))
			{
				if (!isalpha(c))
					break;
				else
					temp = temp + c;
			}

			int espeon = -1;
			for (int i = 0; i < ppl; i++)
			{
				if (names[i] == temp)
				{
					espeon = i;
					break;
				}
			}

			int money;
			cin >> money;
			int left = money;
			net[espeon] = net[espeon] - money;

			int shares;
			cin >> shares;
			if (shares > 0)
				cin.ignore(1000, ' ');
			else
				cin.ignore(1000, '\n');
			for (int s = 0; s < shares; s++)
			{
				string sname = "";
				char cc;
				while (cin.get(cc))
				{
					if (!isalpha(cc))
						break;
					else
						sname = sname + cc;
				}

				int sind = -1;
				for (int j = 0; j < ppl; j++)
				{
					if (names[j] == sname)
					{
						sind = j;
						break;
					}
				}

				net[sind] = net[sind] + money / shares;
				left = left - money / shares;
			}

			net[espeon] = net[espeon] + left;
		}

		for (int i = 0; i < ppl; i++)
			cout << names[i] << " " << net[i] << endl;

	}
	return 0;
}