#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line1;
	string line2;
	int caseno = 1;

	while (getline(cin, line1))
	{
		if (line1 == "#")
			return 0;
		getline(cin, line2);

		int** dp = new int*[line1.length()];
		for (int i = 0; i < line1.length(); i++)
		{
			dp[i] = new int[line2.length()];
			for (int j = 0; j < line2.length(); j++)
			{
				bool match = line1[i] == line2[j];
				int max = 0;
				if (match)
				{
					max++;
					if (i > 0 && j > 0)
						max = dp[i-1][j-1] + 1;
				}
				if (j > 0 && dp[i][j-1] > max)
					max = dp[i][j-1];
				if (i > 0 && dp[i-1][j] > max)
					max = dp[i-1][j];
				dp[i][j] = max;
			}
		}

		int ans;
		if (line1.length() == 0 || line2.length() == 0)
			ans = 0;
		else
			ans = dp[line1.length() - 1][line2.length() - 1];
		cout << "Case #" << caseno << ": you can visit at most " << ans << " cities.\n";
		caseno++;
	}
	return 0;
}