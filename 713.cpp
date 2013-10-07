#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;
	cin.ignore(1000, '\n');

	for (int i = 0; i < ncases; i++)
	{
		string line;
		getline(cin, line);
		string first;
		string second;

		int spaceindex = 0;
		while (line[spaceindex] != ' ')
			spaceindex++;
		first = line.substr(0, spaceindex);
		second = line.substr(spaceindex + 1, line.length() - spaceindex - 1);

		int longerlen = first.length();
		int shorterlen = second.length();
		if (second.length() > longerlen)
		{
			longerlen = second.length();
			shorterlen = first.length();
		}

		int result[200];
		for (int j = 0; j < 200; j++)
			result[j] = 0;

		int index = 0;
		int carry = 0;
		while (index < shorterlen)
		{
			int temp = (first[index] - '0') + (second[index] - '0') + carry;
			carry = temp / 10;
			result[index] = temp % 10;
			index++;
		}
		if (second.length() > first.length())
		{
			while (index < second.length())
			{
				int temp = (second[index] - '0') + carry;
				carry = temp / 10;
				result[index] = temp % 10;
				index++;
			}
		}
		else
		{
			while (index < first.length())
			{
				int temp = (first[index] - '0') + carry;
				carry = temp / 10;
				result[index] = temp % 10;
				index++;
			}
		}
		if (carry > 0)
		{
			result[index] = carry;
			index++;
		}

		int printindex = 0;
		while (result[printindex] == 0)
			printindex++;

		for (int z = printindex; z < index; z++)
			cout << result[z];
		cout << endl;
	}
	return 0;
}
		