#include <iostream>

using namespace std;

int main()
{
	int lines;
	cin >> lines;
	long long a;
	long long b;
	for (int i = 0; i < lines; i++)
	{
		cin >> a >> b;
		if (a < b) cout << "<" << endl;
		else if (a > b) cout << ">" << endl;
		else cout << "=" << endl;
	}
}