#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		if (line == "0")
			return 0;

		//process 8 digits at a time
		int digitsProcessed = 0;
		int current = 0;

		while (digitsProcessed < line.length())
		{
			while (current / 100000000 == 0 && digitsProcessed < line.length())
			{
				char c = line[digitsProcessed];
				current = current*10 + (c - '0');
				digitsProcessed++;
			}
			current = current % 11;
		}

		if (current == 0)
			cout << line << " is a multiple of 11.\n";
		else
			cout << line << " is not a multiple of 11.\n";
	}
	return 0;
}