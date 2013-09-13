#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int getNumFromLetter(char c)
{
	switch(c)
	{
	case 'A':
	case 'B':
	case 'C':
		return 2;
	case 'D':
	case 'E':
	case 'F':
		return 3;
	case 'G':
	case 'H':
	case 'I':
		return 4;
	case 'J':
	case 'K':
	case 'L':
		return 5;
	case 'M':
	case 'N':
	case 'O':
		return 6;
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
		return 7;
	case 'T':
	case 'U':
	case 'V':
		return 8;
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
		return 9;
	default:
		return -1; //error
	}
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		for (int i = 0; i < line.length(); i++)
		{
			if (isalpha(line[i]))
				cout << getNumFromLetter(line[i]);
			else
				cout << line[i];
		}
		cout << endl;
	}
	return 0;
}