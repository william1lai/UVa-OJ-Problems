#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string first;
	string second;

	while (getline(cin, first))
	{
		getline(cin, second);
		int len1 = first.length();
		int len2 = second.length();

		int** table = new int*[len1+1];
		for (int i = 0; i < len1+1; i++)
			table[i] = new int[len2+1];

		for (int i = 0; i < len1+1; i++)
			table[i][0] = 0;

		for (int i = 0; i < len2+1; i++)
			table[0][i] = 0;

		for (int i = 1; i < len1+1; i++)
		for (int j = 1; j < len2+1; j++)
		{
			if (first[i-1] == second[j-1])
				table[i][j] = table[i-1][j-1] + 1;
			else
				table[i][j] = max(table[i-1][j], table[i][j-1]);
		}
		
		cout << table[len1][len2] << endl;

		for (int i = 0; i < len1+1; i++)
			free(table[i]);
		free(table);
	}

	return 0;		
}