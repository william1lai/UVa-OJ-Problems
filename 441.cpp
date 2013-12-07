#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void printPermutations(list<int> left, list<int> used)
{
	if (used.size() == 6)
	{
		for (list<int>::iterator it = used.begin(); it != used.end(); it++)
		{
			if (it != used.begin())
				cout << " ";
			cout << *it;
		}
		cout << "\n";
		return;
	}

	list<int>::iterator it = left.begin();
	while (left.size() + used.size() >= 6)
	{
		list<int> temp = used;
		temp.push_back(*it);
		it = left.erase(it);
		printPermutations(left, temp);
	}

	return;
}


int main()
{
	int n;
	bool first = true;
	while (cin >> n)
	{
		if (n == 0)
			return 0;

		if (first)
			first = false;
		else
			cout << "\n";

		list<int> nums;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			nums.push_back(temp);
		}
		nums.sort();

		list<int> empty;
		printPermutations(nums, empty);
	}
	return 0;
}