#include <iostream>
#include <string>

using namespace std;

bool areMirrored(char a, char b)
{
	switch (a)
	{
	case 'A': case 'H':
	case 'I': case 'M':
	case 'O': case 'T':
	case 'U': case 'V':
	case 'W': case 'X':
	case 'Y': case '1':
	case '8': case '0':
		return (a == b);
	case 'E': return (b == '3');
	case 'J': return (b == 'L');
	case 'L': return (b == 'J');
	case 'S': return (b == '2');
	case 'Z': return (b == '5');
	case '2': return (b == 'S');
	case '3': return (b == 'E');
	case '5': return (b == 'Z');
	default: return false;
	}
}

int main()
{
	string line;

	while (getline(cin, line))
	{
		
		bool isPalindrome = true;
		bool isMirrored = true;

		for (int i = 0; i <= line.length() / 2; i++)
		{
			char left = line[i];
			char right = line[line.length() - i - 1];

			if (left != right)
				isPalindrome = false;
			if (! areMirrored(left, right))
				isMirrored = false;
		}
	
		cout << line << " -- is ";
		if (isPalindrome && isMirrored)
			cout << "a mirrored palindrome." << endl;
		else if (isPalindrome)
			cout << "a regular palindrome." << endl;
		else if (isMirrored)
			cout << "a mirrored string." << endl;
		else
			cout << "not a palindrome." << endl;
		cout << endl;
	}

	return 0;
}