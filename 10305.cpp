#include <iostream>
#include <list>

using namespace std;

int main()
{
	int m;
	int n;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			return 0;

		bool first = true;
		list<int>* adj = new list<int>[n];
		int* degs = new int[n];
		bool* processed = new bool[n];

		for (int i = 0; i < n; i++)
		{
			degs[i] = 0;
			processed[i] = false;
		}

		for (int i = 0; i < m; i++)
		{
			int f;
			int s;
			cin >> f >> s;

			adj[f-1].push_back(s-1);
			degs[s-1]++;
		}

		int left = n;
		while (left > 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (degs[i] == 0 && !processed[i])
				{
					if (!first)
						cout << " ";
					else
						first = false;

					cout << i + 1;
	
					for (list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++)
						degs[*it]--;

					left--;
					processed[i] = true;

					if (left <= 0)
						break;
				}
			}
		}
		cout << "\n";
	}
	return 0;
}