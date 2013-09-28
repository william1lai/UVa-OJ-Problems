#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string line1;
	string line2;
	while (getline(cin, line1) && getline(cin, line2))
	{
		sort(line1.begin(), line1.end());
		sort(line2.begin(), line2.end());

		string match = "";
		int index1 = 0;
		int index2 = 0;
		while (index1 < line1.length() && index2 < line2.length())
		{
			if (line1[index1] == line2[index2])
			{
				match = match + line1[index1];
				index1++;
				index2++;
			}
			else if (line1[index1] < line2[index2])
			{
				index1++;
			}
			else
			{
				index2++;
			}
		}

		cout << match << endl;
	}
	return 0;
}