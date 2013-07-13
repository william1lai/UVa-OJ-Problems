#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	unsigned long lights;
	cin >> lights;

	while (lights != 0)
	{
		double root = sqrt(1.0 * lights);
		double norm = ceil(root);

		if (abs(root - norm) < 1E-10 || abs(root - norm) > (1 - 1E-10))
			cout << "yes\n";
		else
			cout << "no\n";

		cin >> lights;
	}
}