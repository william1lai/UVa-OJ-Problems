#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

void flipFlapjacks(deque<int> stack, int bottom)
{
	int workingSize = stack.size() - bottom + 1;
	if (workingSize == 1) //only one left (or special case where only one element)
	{
		cout << "0" << endl;
		return;
	}

	bool isSorted = true;
	for (int i = 0; i < workingSize - 1; i++)
	{
		if (stack[i] > stack[i+1])
		{
			isSorted = false;
			break;
		}
	}

	if (isSorted)
	{
		cout << "0" << endl;
		return;
	}

	int max = *max_element(stack.begin(),stack.begin() + workingSize);
	int maxIndex;
	for (int i = 0; i < workingSize; i++)
	{
		if (stack[i] == max) 
		{
			maxIndex = i;
			break;
		}
	}
	
	deque<int> smaller;
	if (maxIndex != workingSize - 1)
	{
		if (maxIndex != 0)
			cout << workingSize - maxIndex + bottom - 1 << " ";
		cout << bottom << " ";

		for (int i = maxIndex + 1; i < workingSize; i++)
			smaller.push_front(stack[i]);
	}
	
	for (int i = 0; i <= maxIndex; i++)
		smaller.push_back(stack[i]);
	for (int i = workingSize; i < stack.size(); i++)
		smaller.push_back(stack[i]);

	flipFlapjacks(smaller, bottom + 1);	
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		cout << line << endl;
		stringstream oss(line);
		deque<int> flapjacks;
		int temp;
		while (oss >> temp)
			flapjacks.push_back(temp);

		flipFlapjacks(flapjacks, 1);
	}

	return 0;
}