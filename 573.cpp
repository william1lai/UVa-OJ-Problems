#include <iostream>

using namespace std;

int main()
{
	double height;
	double climb;
	double slide;
	double fatigue;
	while (cin >> height >> climb >> slide >> fatigue)
	{
		if (height == 0)
			return 0;

		double loss = climb * fatigue / 100;
		int day = 1;
		double progress = 0;

		while (true)
		{
			//day
			progress = progress + climb;
			if (progress > height)
			{
				cout << "success on day " << day << endl;
				break;
			}
			
			//night
			progress = progress - slide;
			climb = climb - loss;
			if (climb < 0)
				climb = 0;
			if (progress < 0)
			{
				cout << "failure on day " << day << endl;
				break;
			}

			day++;
		}
	}
	return 0;
}