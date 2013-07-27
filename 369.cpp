#include <iostream>

using namespace std;

int main()
{
	double M;
	double  N;
	cin >> N >> M;
	while (N > 0)
	{
		double temp = M;
		if (M > N / 2) temp = N - M;
		double combo = 1;

		for (double i = 0; i < temp; i++)
		{
			combo = combo * (N - i) / (i + 1);
		}

		cout << N << " things taken "
		     << M << " at a time is "
		     << (long long)combo << " exactly." << endl;

		cin >> N >> M;
	}

	return 0;
}