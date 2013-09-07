#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
	string keyboard[3];
	keyboard[0] = "qwertyuiop[]\\";
	keyboard[1] = "asdfghjkl;\'";
	keyboard[2] = "zxcvbnm,./";

	string line;
	while (getline(cin, line))
	{
		string mline = line;
		transform(mline.begin(), mline.end(), mline.begin(), ::tolower);
		for (int i = 0; i < mline.length(); i++)
		{
			if (mline[i] == ' ') 
			{
				cout << ' ';
				continue;
			}

			for (int j = 0; j < 3; j++)
			{
				bool changed = false;
				for (int k = 2; k < keyboard[j].length(); k++)
				{
					if (mline[i] == keyboard[j][k])
					{
						cout << keyboard[j][k-2];
						changed = true;
						break;
					}
				}
				if (changed) break;
			}
		}
		cout << endl;
	}
	return 0;
}