#include <cmath>
#include <iostream>
#include "stdio.h"

using namespace std;

int main()
{
	double root;
	double base;
	while (cin >> root >> base)
	{
		printf("%1.0f\n", pow(base, 1.0/root));
	}
	return 0;
}