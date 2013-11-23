#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	map<string, int> dict;
	set<string> words;
	string next;
	while (cin >> next)
	{
		if (next == "#")
			break;

		string temp = "";
		for (int i = 0; i < next.length(); i++)
			temp = temp + (char)tolower(next[i]);
		sort(temp.begin(), temp.end());

		words.insert(next);

		map<string, int>::iterator it = dict.find(temp);
		if (it != dict.end())
			it->second++;
		else
		{
			pair<string, int> p(temp, 1);
			dict.insert(p);
		}
	}

	for (set<string>::iterator it = words.begin(); it != words.end(); it++)
	{
		string w = *it;
		for (int i = 0; i < w.length(); i++)
			w[i] = tolower(w[i]);
		sort(w.begin(), w.end());
		map<string, int>::iterator dit = dict.find(w);
		if (dit != dict.end())
		{
			if (dit->second == 1)
				cout << *it << "\n";
		}
	}
	return 0;
}