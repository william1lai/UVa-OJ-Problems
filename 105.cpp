#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int skyline[10000];
	memset(skyline, 0, 10000*sizeof(int));

	int first;
	int height;
	int last;
	while (cin >> first >> height >> last)
	{
		for (int i = first; i < last; i++)
		{
			if (height > skyline[i])
				skyline[i] = height;
		}
	}

	int index = 1;
	int theight;
	while (index <= last)
	{
		int tfirst = index;
		theight = skyline[index];

		if (index != 1) cout << " ";

		while (skyline[index] == theight)
			index++;


		cout << tfirst << " " << theight;
	}
	if (theight != 0)
	{
		cout << " " << index << " 0";
	}
	cout << endl;

	return 0;
}