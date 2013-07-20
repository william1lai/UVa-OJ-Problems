#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define WHITE -1
#define BLACK 1

struct Entry
{
	int color;
	int index;
};

int main()
{
	int nNodes;
	int nEdges;

	cin >> nNodes;
	while (nNodes != 0)
	{
		cin >> nEdges;
		vector<int>* edges = new vector<int>[nNodes];

		int f, s;
		for (int i = 0; i < nEdges; i++)
		{
			cin >> f >> s;
			edges[f].push_back(s);
		}

		int* colors = new int[nNodes];
		for (int i = 0; i < nNodes; i++)
			colors[i] = 0;

		stack<Entry> entries;
		Entry first;
		first.index = 0;
		first.color = WHITE;
		entries.push(first);
		bool result = false;
		while (!entries.empty())
		{
			Entry curr = entries.top();
			entries.pop();

			for (vector<int>::iterator it = edges[curr.index].begin(); it != edges[curr.index].end(); it++)
			{
				int node = *it;
				if (colors[node] == 0)
				{
					colors[node] = -curr.color;
					Entry next;
					next.color = -curr.color;
					next.index = node;
					entries.push(next);
				}
				else if (colors[node] == curr.color)
				{
					cout << "NOT BICOLORABLE." << endl;
					result = true;
					break;
				}
			}
		}
		if (! result) cout << "BICOLORABLE.\n";
		cin >> nNodes;
	}

	return 0;				
}