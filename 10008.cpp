#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

struct letterCounter
{
	char letter;
	int count;
};

void swap(letterCounter* arr, int f, int s)
{
	letterCounter temp = arr[f];
	arr[f] = arr[s];
	arr[s] = temp;
}

void insertionSort(letterCounter* arr)
{
	int n = 26;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j-1].count < arr[j].count)
				swap(arr, j, j-1);
			else if (arr[j-1].count == arr[j].count)
			{
				if (arr[j-1].letter > arr[j].letter)
					swap(arr, j, j-1);
			}
			else break;
		}
	}
}

int main()
{
	int nlines;
	cin >> nlines;
	cin.ignore(1000, '\n');

	letterCounter arr[26];

	for (int i = 0; i < 26; i++)
	{
		arr[i].letter = 'a' + i;
		arr[i].count = 0;	
	}

	for (int i = 0; i < nlines; i++)
	{
		string line;
		getline(cin, line);
		
		for (int j = 0; j < line.length(); j++)
		{
			char c = tolower(line[j]);
			if (isalpha(c))
			{
				arr[c - 'a'].count++;
			}
		}
	}

	insertionSort(arr);

	for (int i = 0; i < 26; i++)
	{
		if (arr[i].count == 0) break;
		cout << char(toupper(arr[i].letter)) << " " << arr[i].count << endl;
	}		

	return 0;
}