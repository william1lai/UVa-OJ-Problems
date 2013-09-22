#include <iostream>
#include <vector>

using namespace std;

struct IntCount
{
	int value;
	int count;
};

int main()
{
	vector<IntCount> myList;

	int n;
	while (cin >> n)
	{
		bool processed = false;
		for (int i = 0; i < myList.size(); i++)
		{
			if (n == myList[i].value)
			{
				myList[i].count++;
				processed = true;
				break;
			}
		}

		if (!processed)
		{
			IntCount temp;
			temp.value = n;
			temp.count = 1;
			myList.push_back(temp);
		}
	}

	for (int i = 0; i < myList.size(); i++)
	{
		cout << myList[i].value << " " << myList[i].count << endl;
	}

	return 0;
}