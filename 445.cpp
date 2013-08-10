#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		int index = 0;

		if (line.length() == 0)
		{
			cout << endl;
			continue;
		}

		while (index < line.length())
		{
		
			if (line[index] == '!')
			{
				cout << endl;
				index++;
				continue;
			}
					
			int num = 0;
			char c;

			while (isdigit(line[index]))
			{
				num = num + (line[index] - '0');
				index++;
			}
			c = line[index];
			index++;
	
			for (int i = 0; i < num; i++)
			{
				if (c == 'b')
					cout << " ";
				else
					cout << c;
			}
		}
		cout << endl;
	}

	return 0;
}