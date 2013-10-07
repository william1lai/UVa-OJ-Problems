#include <iostream>
#include "stdio.h"

using namespace std;

int main()
{
	unsigned long long ways[6001];

	//5c +1
	for (int i = 0; i < 6001; i++)
		ways[i] = 1;

	//10c +2
	for (int i = 2; i < 6001; i++)
		ways[i] = ways[i] + ways[i-2];

	//20c +4
	for (int i = 4; i < 6001; i++)
		ways[i] = ways[i] + ways[i-4];

	//50c +10
	for (int i = 10; i < 6001; i++)
		ways[i] = ways[i] + ways[i-10];

	//$1 +20
	for (int i = 20; i < 6001; i++)
		ways[i] = ways[i] + ways[i-20];

	//$2 +40
	for (int i = 40; i < 6001; i++)
		ways[i] = ways[i] + ways[i-40];

	//$5 +100
	for (int i = 100; i < 6001; i++)
		ways[i] = ways[i] + ways[i-100];

	//$10 +200
	for (int i = 200; i < 6001; i++)
		ways[i] = ways[i] + ways[i-200];

	//$20 +400
	for (int i = 400; i < 6001; i++)
		ways[i] = ways[i] + ways[i-400];

	//$50 +1000
	for (int i = 1000; i < 6001; i++)
		ways[i] = ways[i] + ways[i-1000];

	//$100 +2000
	for (int i = 2000; i < 6001; i++)
		ways[i] = ways[i] + ways[i-2000];

	double change;
	while (cin >> change)
	{
		if (change == 0.0f)
			return 0;

		int cents = (int)(change*100);
		int index = cents / 5;

		if (cents % 5 != 0)
			printf("%3d.%02d%17llu\n", cents / 100, cents % 100, 0);
		else
			printf("%3d.%02d%17llu\n", cents / 100, cents % 100, ways[index]);
	}
	return 0;
}