#include <iostream>
#include "stdio.h"
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

int main()
{
	double x1, y1, x2, y2, x3, y3;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
	{
		double a, b, c;
		a = sqrt((y3-y2)*(y3-y2) + (x3-x2)*(x3-x2));
		b = sqrt((y3-y1)*(y3-y1) + (x3-x1)*(x3-x1));
		c = sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));

		double diam = (2*a*b*c) / sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c));
		printf("%.2f\n", diam*PI);
	}
	return 0;
}