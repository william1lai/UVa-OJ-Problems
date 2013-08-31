#include <iostream>

using namespace std;

int main()
{
	long long n;
	while (cin >> n)
	{
		long long pikachu = (n * (n+1)) / 2;
		cout << pikachu * pikachu << endl;
	}
	return 0;
}