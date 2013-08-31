#include <iostream>

using namespace std;

int gcf(int first, int second)
{
	while (first % second != 0 && second % first != 0)
	{
		if (first > second)
			first = first % second;
		else
			second = second % first;
	}

	if (first < second)
		return first;
	else
		return second;
}

int main()
{
	int n;
	int k;
	cin >> n >> k;
	while (n != 0)
	{
		if (k > n/2) 
			k = n - k;

		int* terms = new int[k];
		for (int i = 0; i < k; i++)
		{
			terms[i] = n - i;
		}

		for (int i = k; i >= 2; i--)
		{
			int divisor = i;
			for (int j = 0; j < k; j++)
			{
				int factor = gcf(terms[j], divisor);
				if (factor > 1)
				{
					terms[j] = terms[j] / factor;
					divisor = divisor / factor;
				}
				if (divisor == 1)
					break;
			}
		}

		int ans = 1;
		for (int i = 0; i < k; i++)
		{
			ans = ans * terms[i];
		}
		cout << ans << endl;
		cin >> n >> k;
	}
	return 0;
}