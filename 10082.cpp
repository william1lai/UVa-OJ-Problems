#include <iostream>

using namespace std;

int main()
{
	char keys[49]
		= { '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', };


	string line;
	while (getline(cin, line))
	{
		int i;
		size_t length = line.length();
		for (i = 0; i < length; i++)
		{
			char c = line[i];
			if (c == ' ') cout << " ";
			else
			{
				int j = 0;
				while (keys[j] != c) j++;
				cout << keys[j-1];
			}
		}
		cout << endl;
	}
	return 0;
}