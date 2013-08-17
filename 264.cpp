#include <iostream>

using namespace std;

int main()
{
	int index;
	while (cin >> index)
	{
		int diag = 1;
		int temp = index;
		while (temp - diag > 0)
		{
			temp = temp - diag;
			diag++;
		}

		cout << "TERM " << index << " IS ";

		if (diag % 2 == 1)
			cout << diag - temp + 1 << "/" << temp << endl;
		else
			cout << temp << "/" << diag - temp + 1 << endl;
	}
	return 0;
}