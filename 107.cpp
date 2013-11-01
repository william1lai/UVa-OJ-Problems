#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long height;
	long long workers;
	while (cin >> height >> workers)
	{
		if (height == 0)
			return 0;

		long long power = 2;
		long long root = -1;

		if (workers != 1 && height - 1 != workers)
		{
			while (true)
			{
				long long p = pow(height, 1.0 / power) + 0.001;
				if (pow(p, power) == height && pow(p - 1, power) == workers)
				{
					root = p;
					break;
				}
				power++;
			}
		}

		long long nonworkers = 0;
		long long sum = 0;
		long long root2 = root - 1;
		long long tempheight = 1;

		if (workers == 1 || root2 == 1)
		{
			nonworkers = 0;
			sum = 1;
			while (tempheight < height)
			{
				tempheight = tempheight*2;
				nonworkers++;
				sum = sum + tempheight;
			}
		}
		else if (workers + 1 == height)
		{
			nonworkers = 1;
			sum = height + workers;
		}
		else
		{
			while (workers > 0)
			{
				sum = sum + workers*tempheight;
				workers = workers / root2;
				nonworkers = nonworkers + workers;
				tempheight = tempheight*root;
			}
		}

		cout << nonworkers << " " << sum << "\n";
	}
	return 0;
}