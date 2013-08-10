#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

struct LetterCount
{
	char letter;
	int count;
};

int compare(const LetterCount &f, const LetterCount &s)
{
	if (f.count == s.count)
	{
		if (isupper(f.letter))
		{
			if (isupper(s.letter)) return ((f.letter - s.letter) < 0);
			else return true;
		}
		else
		{
			if (isupper(s.letter)) return false;
			else return ((f.letter - s.letter) < 0);
		}
	}
	return ((s.count - f.count) < 0);
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		vector<LetterCount> arr;
		for (int i = 0; i < 26; i++)
		{
			LetterCount lc;
			lc.letter = 'A' + i;
			lc.count = 0;
			arr.push_back(lc);
		}
		for (int i = 0; i < 26; i++)
		{
			LetterCount lc;
			lc.letter = 'a' + i;
			lc.count = 0;
			arr.push_back(lc);
		}

		for (int i = 0; i < line.length(); i++)
		{
			char c = line[i];
			if (isalpha(c))
			{
				if (isupper(c))	arr[c - 'A'].count++;
				else arr[c - 'a' + 26].count++;
			}
		}

		sort(arr.begin(), arr.end(), compare);

		int max = arr[0].count;
		int index = 1;
		while (arr[index].count == max)
		{
			index++;
		}	

		for (int i = 0; i < index; i++)
		{
			cout << arr[i].letter;
		}
		cout << " " << max << endl;
	}

	return 0;
}