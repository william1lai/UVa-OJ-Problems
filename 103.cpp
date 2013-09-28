#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int* map;

struct Box
{
	vector<int> dims;
	int id;
};

bool compare(Box f, Box s)
{
	for (int i = 0; i < f.dims.size(); i++)
	{
		if (f.dims[i] > s.dims[i])
			return false;
		else if (f.dims[i] < s.dims[i])
			return true;
	}
	return false;
}

bool fits(Box f, Box s)
{
	for (int i = 0; i < f.dims.size(); i++)
	{
		if (f.dims[i] >= s.dims[i])
			return false;
	}
	return true;
}

vector<int> helper(bool** graph, vector<Box> boxes, vector<int> order) //second attempt pretty much the same as first: O(2^N)
{
	vector<int> longest;
	int longestlength = 0;
	int size = boxes.size();
	if (order.empty())
	{
		for (int i = 0; i < size; i++)
		{
			vector<int> v;
			v.push_back(i);
			vector<int> res = helper(graph, boxes, v);

			if (res.size() > longestlength)
			{
				longestlength = res.size();
				longest = res;
			}
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (graph[order[order.size() - 1]][i])
			{
				vector<int> v(order);
				v.push_back(i);
				vector<int> ret = helper(graph, boxes, v);

				if (ret.size() > longestlength)
				{
					longestlength = ret.size();
					longest = ret;
				}
			}
		}
	}
	if (longestlength == 0) //base case
		return order;
	return longest;
}

vector<int> helper2(bool** graph, vector<Box> boxes) //DP solution is O(N^2), much faster
{
	int size = boxes.size();
	vector<int>* path = new vector<int>[size];
	int* longest = new int[size];
	for (int i = 0; i < size; i++)
	{
		longest[i] = 1;
		path[i].push_back(map[i]);
	}

	int max = 0;
	int longestIndex = -1;
	for (int i = 1; i < size; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (longest[j] + 1 > longest[i] && graph[j][i])
			{
				longest[i] = longest[j] + 1;
				path[i] = path[j];
				path[i].push_back(map[i]);
			}
		}

		if (longest[i] > max)
		{
			max = longest[i];
			longestIndex = i;
		}
	}
	return path[longestIndex];
}

vector<int> findLongest(vector<Box> boxes)
{
	int size = boxes.size();
	bool** graph = new bool*[size];
	for (int i = 0; i < size; i++)
	{
		graph[i] = new bool[size];
		for (int j = 0; j < size; j++)
			graph[i][j] = fits(boxes[i], boxes[j]);
	}

	return helper2(graph, boxes);
	//return helper(graph, boxes, vector<int>());
}

vector<int> findLongest(vector<Box> boxes, vector<int> order, int index) //decision tree version too inefficient O(2^N)
{
	if (index >= boxes.size())
		return order;

	if (order.empty())
	{
		vector<int> without = findLongest(boxes, order, index + 1);
		order.push_back(index);
		vector<int> with = findLongest(boxes, order, index + 1);

		if (without.size() > with.size())
			return without;
		else
			return with;
	}
	else
	{
		int last = order[order.size() - 1];
		vector<int> without = findLongest(boxes, order, index + 1);

		if (fits(boxes[last], boxes[index]))
		{
			order.push_back(index);
			vector<int> with = findLongest(boxes, order, index + 1);

			if (without.size() > with.size())
				return without;
			else
				return with;
		}
		else
		{
			return without;
		}
	}	
}

int main()
{
	int num;
	int dims;

	while (cin >> num >> dims)
	{
		vector<Box> boxes;
		for (int i = 1; i <= num; i++)
		{
			Box b;
			b.id = i;
			for (int j = 0; j < dims; j++)
			{
				int temp;
				cin >> temp;
				b.dims.push_back(temp);
			}
			sort(b.dims.begin(), b.dims.end());
			boxes.push_back(b);
		}

		sort(boxes.begin(), boxes.end(), compare);
		map = new int[num];
		for (int i = 0; i < boxes.size(); i++)
		{
			map[i] = boxes[i].id;
		}

		vector<int> empty;
		vector<int> order = findLongest(boxes);

		cout << order.size() << endl;
		cout << order[0];
		for (int i = 1; i < order.size(); i++)
		{
			cout << " " << order[i];
		}
		cout << endl;
	}
	return 0;
}