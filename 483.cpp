#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	char c;
	while(cin.get(c))
	{
		if (isspace(c)) cout << c;
		else
		{
			string s = "";
			while (! isspace(c))
			{
				s = c + s;
				cin.get(c);
			}
			cout << s;
			cin.putback(c);
		}
	}

	return 0;
}