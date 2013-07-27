#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long cigNum;
	long long recycle;

	while (cin >> cigNum >> recycle)
	{
		long long sum = cigNum;
		while (cigNum > 0)
		{
			long long temp = cigNum % recycle;
			cigNum = cigNum / recycle;
			sum = sum + cigNum;

			if (cigNum > 0) cigNum = cigNum + temp;
		}
		cout << sum << endl;
	}

	return 0;
}