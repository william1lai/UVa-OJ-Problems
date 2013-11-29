#include <iostream>
#include <iomanip>

using namespace std;

int tryNqueens(int weights[8][8], int r, int c)
{
	int ans = weights[r][c];
	if (r == 7)
		return ans;

	int weightsclone[8][8];
	for (int rr = 0; rr < 8; rr++)
	for (int c = 0; c < 8; c++)
		weightsclone[rr][c] = weights[rr][c];

	for (int i = 0; i < 8; i++)
	{
		weightsclone[i][c] = -1;
		weightsclone[r][i] = -1;
		
		int diag1 = i + r - c;
		if (diag1 < 8 && diag1 >= 0)
			weightsclone[diag1][i] = -1;

		int diag2 = r + c - i;
		if (diag2 < 8 && diag2 >= 0)
			weightsclone[diag2][i] = -1;
	}
	r++;
	
	int max = -1;
	for (int c = 0; c < 8; c++)
	{
		int temp;
		if (weightsclone[r][c] != -1)
		{
			temp = tryNqueens(weightsclone, r, c);
			if (temp > max)
				max = temp;
		}
	}

	if (max < 0)
		return -9000;
	
	return ans + max;
}

int main()
{
	int nboards;
	cin >> nboards;

	for (int i = 0; i < nboards; i++)
	{
		int weights[8][8];
		for (int r = 0; r < 8; r++)
		for (int c = 0; c < 8; c++)
			cin >> weights[r][c];

		int max = -1;
		for (int j = 0; j < 8; j++)
		{
			int ans = tryNqueens(weights, 0, j);
			if (ans > max)
				max = ans;
		}

		cout << setw(5);
		cout << max << "\n";
	}
	return 0;
}