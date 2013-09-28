#include <iostream>
#include <string>
#include <cctype>
#include "stdio.h"

using namespace std;

int score(string name)
{
	int sum = 0;
	for (int i = 0; i < name.length(); i++)
	{
		char c = name[i];
		if (isalpha(c))
		{
			if (isupper(c))
				sum = sum + c - 'A' + 1;
			else
				sum = sum + c - 'a' + 1;
		}
	}

	while (sum >= 10)
	{
		sum = (sum % 10) + (sum / 10);
	}

	return sum;
}

int main()
{
	string first;
	string second;
	while (getline(cin, first) && getline(cin, second))
	{
		int score1 = score(first);
		int score2 = score(second);

		double ratio = 0.0;
		if (score1 > score2)
			ratio = 100.0 * score2 / score1;
		else
			ratio = 100.0 * score1 / score2;

		printf("%.2f %%\n", ratio);
	}

	return 0;
}