#include <iostream>
#include <climits>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int rows;
	int cols;
	while (cin >> rows >> cols)
	{
		long long** weights = new long long*[rows];
		long long** minimal = new long long*[rows];
		int** parent = new int*[rows];
		for (int r = 0; r < rows; r++)
		{
			weights[r] = new long long[cols];
			minimal[r] = new long long[cols];
			parent[r] = new int[cols];
			for (int c = 0; c < cols; c++)
			{
				cin >> weights[r][c];

				if (c == cols - 1)
					minimal[r][c] = weights[r][c];
				else
					minimal[r][c] = LLONG_MAX;
	
				parent[r][c] = -1;
			}
		}

		for (int c = cols - 1; c > 0; c--)
		{
			for (int r = 0; r < rows; r++)
			{
				if (r == 0)
				{
					if (minimal[r][c] + weights[rows - 1][c - 1] < minimal[rows - 1][c - 1])
					{
						minimal[rows - 1][c - 1] = minimal[r][c] + weights[rows - 1][c - 1];
						parent[rows - 1][c - 1] = r;
					}
				}
				else
				{
					if (minimal[r][c] + weights[r - 1][c - 1] < minimal[r - 1][c - 1])
					{
						minimal[r - 1][c - 1] = minimal[r][c] + weights[r - 1][c - 1];
						parent[r - 1][c - 1] = r;
					}
				}

				if (minimal[r][c] + weights[r][c - 1] < minimal[r][c - 1])
				{
					minimal[r][c - 1] = minimal[r][c] + weights[r][c - 1];
					parent[r][c - 1] = r;
				}
				
				if (r == rows - 1)
				{
					if (minimal[r][c] + weights[0][c - 1] < minimal[0][c - 1])
					{
						minimal[0][c - 1] = minimal[r][c] + weights[0][c - 1];
						parent[0][c - 1] = r;
					}
				}
				else
				{
					if (minimal[r][c] + weights[r + 1][c - 1] < minimal[r + 1][c - 1])
					{
						minimal[r + 1][c - 1] = minimal[r][c] + weights[r + 1][c - 1];
						parent[r + 1][c - 1] = r;
					}
				}
			}
		}

		int min = minimal[0][0];
		int minIndex = 0;
		for (int r = 1; r < rows; r++)
		{
			if (minimal[r][0] < min)
			{
				min = minimal[r][0];
				minIndex = r;
			}
		}

		ostringstream oss;
		oss << (minIndex + 1);
		for (int c = 0; c < cols - 1; c++)
		{
			minIndex = parent[minIndex][c];
			int temp = minIndex + 1;
			oss << " " << temp;
		}

		string output = oss.str();
		cout << output << "\n" << min << "\n";

	}
	return 0;
}