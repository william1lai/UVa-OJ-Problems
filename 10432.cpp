#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double r;
	int n;
	while (cin >> r >> n)
	{
		double ans = (1.0*n*r*r/2)*sin(2*acos(-1)/n);
		cout << fixed << setprecision(3) << ans << "\n";
	}
	return 0;
}