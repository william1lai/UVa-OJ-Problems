#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ASCII
{
	int sym;
	int count;
};

bool isLessThan(ASCII f, ASCII s)
{
	if (f.count == s.count)
		return f.sym > s.sym;

	return f.count < s.count;
}

int main()
{
	bool firstLine = true;

	string line;
	while (getline(cin, line))
	{
		if (firstLine)
			firstLine = false;
		else
			cout << endl;

		int ascii[256];
		for (int i = 0; i < 256; i++)
			ascii[i] = 0;

		for (int i = 0; i < line.length(); i++)
			ascii[line[i]]++;

		vector<ASCII> pikachu;
		for (int i = 32; i < 128; i++)
		{
			if (ascii[i] > 0)
			{
				ASCII temp;
				temp.sym = i;
				temp.count = ascii[i];
				pikachu.push_back(temp);
			}
		}

		sort(pikachu.begin(), pikachu.end(), isLessThan);

		for (int i = 0; i < pikachu.size(); i++)
			cout << pikachu[i].sym << " " << pikachu[i].count << endl;
	}
	return 0;
}