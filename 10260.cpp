#include <iostream>
#include <string>

using namespace std;

string getCode(char c)
{
	switch (c)
	{
	case 'B':
	case 'F':
	case 'P':
	case 'V':
		return "1";
	case 'C':
	case 'G':
	case 'J':
	case 'K':
	case 'Q':
	case 'S':
	case 'X':
	case 'Z':
		return "2";

	case 'D':
	case 'T':
		return "3";
	case 'L':
		return "4";
	case 'M':
	case 'N':
		return "5";
	case 'R':
		return "6";
	default:
		return "";
	}
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		string code = "";
		string lastcode = "";

		for (int i = 0; i < line.length(); i++)
		{
			string temp = getCode(line[i]);
			if (lastcode[0] != temp[0])
			{
				code = code + temp;
				lastcode = temp;
			}
		}
		cout << code << endl;
	}
	return 0;
}