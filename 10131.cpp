#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct Container
{
	int weight;
	int iq;
	int id;
};

bool isLT(Container f, Container s)
{
	if (f.weight == s.weight)
		return f.iq < s.iq;

	return f.weight < s.weight;
}

int main()
{
	int w;
	int iq;
	int id = 1;
	vector<Container> elefantes;

	while (cin >> w >> iq)
	{
		//if (w == 0)
			//break;

		Container elefante;
		elefante.weight = w;
		elefante.iq = iq;
		elefante.id = id;
		elefantes.push_back(elefante);
		id++;
	}

	sort(elefantes.begin(), elefantes.end(), isLT);

	int n = id - 1;
	int* len = new int[n];
	int* parent = new int[n];
	for (int i = 0; i < n; i++)
	{
		len[i] = 1;
		parent[i] = -1;
	}

	for (int i = 0; i < n; i++)
	{
		Container elefante = elefantes[i];
		for (int j = i; j < n; j++)
		{
			if (elefante.weight < elefantes[j].weight && elefante.iq > elefantes[j].iq)
			{
				if (len[i] + 1 > len[j])
				{
					len[j] = len[i] + 1;
					parent[j] = i;
				}
			}
		}
	}

	int maxLen = 0;
	int maxIndex = -1;
	for (int i = 0; i < n; i++)
	{
		if (len[i] > maxLen)
		{
			maxLen = len[i];
			maxIndex = i;
		}
	}

	int temp = maxIndex;
	stack<int> vals;

	while (temp != -1)
	{
		vals.push(elefantes[temp].id);
		temp = parent[temp];
	}

	cout << maxLen << endl;
	while (!vals.empty())
	{
		cout << vals.top() << endl;
		vals.pop();
	}
	return 0;
}