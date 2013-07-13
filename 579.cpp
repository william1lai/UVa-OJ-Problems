#include <iostream>
#include <cstdlib>
#include "stdio.h"

using namespace std;

int main()
{
	int hour;
	int minute;

	cin >> hour;
	cin.ignore(1, ':');
	cin >> minute;
	while (! ((hour == 0) && (minute == 0)))
	{
		double hourAngle = ((hour + (minute / 60.0)) / 12.0 * 360.0);
		double minuteAngle = minute / 60.0 * 360.0;
		double angleDiff;
		if (hourAngle > minuteAngle) angleDiff = hourAngle - minuteAngle;
		else angleDiff = minuteAngle - hourAngle;

		while (angleDiff > 180.0) angleDiff = angleDiff - 180.0;

		printf("%.3f\n", angleDiff);

		cin >> hour;
		cin.ignore(1, ':');
		cin >> minute;
	}
}