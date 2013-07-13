#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;
	while (num != 0)
	{
		cout << "f91(" << num << ") = ";

		if (num > 100) cout << (num - 10);
		else cout << "91";

		cout << endl;
		cin >> num;
	}

	return 0;
}