#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;
	getline(cin, line);
	int index = line.length() - 1;
	while (line != "0")
	{
		int sum = 0;
		int digit = 1; //this is k+1

		while (index >= 0)
		{
			char next = line[index];
			index = index - 1;
			int i = next - '0';
			//int partial = (2 << digit) - 1;
			//sum = sum + (i * partial);
			sum = sum + (i * ((1 << digit) - 1));
			digit = digit + 1;
		}
		cout << sum << endl;

		getline(cin, line);
		index = line.length() - 1;			
	}

	return 0;
}