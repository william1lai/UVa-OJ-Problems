#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N > 0)
	{
		for (int m = 1; ; m++)
		{
			vector<int> on;
			for (int z = 2; z <= N; z++)
				on.push_back(z);

			int index = -1;

			while (on.size() > 1)
			{
				index = (index + m) % on.size();
				int temp = on[index];

				if (temp == 13)
					break;
				else
				{
					on.erase(on.begin() + index);
					index--;
				}
			}

			if (on.size() == 1)
			{
				cout << m << endl;
				break;
			}
		}	

		cin >> N;
	}

	return 0;
}