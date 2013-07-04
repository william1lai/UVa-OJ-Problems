#include <iostream>
#include "stdio.h"

using namespace std;

int main()
{
	int nsets;
	cin >> nsets;

	for (int i =  0; i < nsets; i++)
	{
		int numStudents;
		cin >> numStudents;

		int* scores = new int[numStudents];

		int sum = 0;
		for (int j = 0; j < numStudents; j++)
		{
			cin >> scores[j];
			sum = sum + scores[j];
		}
		double average = 1.0 * sum / numStudents;

		int aboveAvg = 0;
		for (int j = 0; j < numStudents; j++)
		{
			if (double(scores[j]) > average)
			{
				aboveAvg++;
			}
		}
		printf("%2.3f%%\n", 100.0 * aboveAvg / numStudents);
	}
}