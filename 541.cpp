#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N > 0)
	{
		int* rows = new int[N];
		int* cols = new int[N];

		bool** arr = new bool*[N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new bool[N];
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j])
				{
					rows[i]++;
					cols[j]++;
				}
			}
		}

		int oddRows = 0;
		int oddCols = 0;
		for (int i = 0; i < N; i++)
		{
			if (rows[i] % 2 == 1) oddRows++;
			if (cols[i] % 2 == 1) oddCols++;
		}

		if (oddRows == 0 && oddCols == 0)
			cout << "OK" << endl;
		else if (oddRows == 1 && oddCols == 1)
		{
			int r, c;
			for (int i = 0; i < N; i++)
			{
				if (rows[i] % 2 == 1) r = i;
				if (cols[i] % 2 == 1) c = i;
			}
			cout << "Change bit (" << r+1 << "," << c+1 << ")" << endl;
		}
		else
			cout << "Corrupt" << endl;

		cin >> N;
	}
}