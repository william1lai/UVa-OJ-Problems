#include <iostream>
#include <string>

using namespace std;

struct BoundPair
{
	int lower;
	int upper;
};

struct Array
{
	string name;
	int base_addr;
	int size;
	int dim;
	BoundPair* bounds;
};

int main()
{
	int narr;
	int nrefs;
	cin >> narr >> nrefs;

	Array* arrs = new Array[narr];
	for (int i = 0; i < narr; i++)
	{
		cin >> arrs[i].name;
		cin >> arrs[i].base_addr;
		cin >> arrs[i].size;
		cin >> arrs[i].dim;
		arrs[i].bounds = new BoundPair[arrs[i].dim];
		for (int j = 0; j < arrs[i].dim; j++)
		{
			cin >> arrs[i].bounds[j].lower;
			cin >> arrs[i].bounds[j].upper;
		}
		cin.ignore(1000, '\n');
	}

	for (int i = 0; i < nrefs; i++)
	{
		string name;
		int* coordinates;

		cin >> name;
		int index;
		for (index = 0; index < narr; index++)
		{
			if (arrs[index].name == name)
				break;
		}
		cout << name << "[";

		int dims = arrs[index].dim;
		coordinates = new int[dims];
		for (int j = 0; j < dims; j++)
		{
			cin >> coordinates[j];
			cout << coordinates[j];
			if (j != dims - 1) cout << ", ";
		}
		cout << "] = ";

		int offset = 0;
		for (int j = 0; j < dims; j++)
		{
			int temp = coordinates[j] - arrs[index].bounds[j].lower;
			for (int k = j+1; k < dims; k++)
			{
				temp = temp * (arrs[index].bounds[k].upper - arrs[index].bounds[k].lower + 1);
			}
			temp = temp * arrs[index].size;
			offset = offset + temp;
		}
		cout << (arrs[index].base_addr + offset) << endl;
	}

	return 0;
}