#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	string sentences[101];
	int count = 0;
	while (getline(cin, sentences[count]))
	{
		count++;
	}

	for (int i = 0; i < 100; i++)
	{
		bool printedSomething = false;
		for (int j = count - 1; j >= 0; j--)
		{
			if (sentences[j].length() > i)
			{
				char c = sentences[j][i];
				if (c != 0)
				{
					cout << c;
					printedSomething = true;
				}
			}
			else
			{
				cout << " ";
			}
		}
		if (printedSomething)	cout << endl;
	}
	return 0;
}