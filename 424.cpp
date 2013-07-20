#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int sum[101]; //each index contains a digit
	for (int i = 0; i < 101; i++)
		sum[i] = 0;

	string line;
	getline(cin, line);

	while (line[0] != '0' || line.length() != 1)
	{
		for (int i = line.length() - 1; i >= 0; i--)
		{
			sum[101 - (line.length() - i)] += (line[i] - '0');
		}

		for (int i = 100; i >= 0; i--)
		{
			while (sum[i] >= 10)
			{
				sum[i - 1]++;
				sum[i] = sum[i] - 10;
			}
		}
		getline(cin, line);
	}

	int index;
	for (index = 0; index < 101; index++) //find first digit
	{
		if (sum[index] > 0) break;
	}

	for (int i = index; i < 101; i++)
	{
		cout << sum[i];
	}
	cout << endl;
}