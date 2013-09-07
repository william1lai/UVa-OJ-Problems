#include <iostream>
#include <vector>

using namespace std;

struct Rectangle
{
	double x1;
	double y1;
	double x2;
	double y2;
};

int main()
{
	vector<Rectangle> rects;

	char c;
	while (cin.get(c))
	{
		if (c == 'r')
		{
			double x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			Rectangle r;
			r.x1 = x1; r.y1 = y1;
			r.x2 = x2; r.y2 = y2;
			rects.push_back(r);
		}
		else //'*'
		{
			double x; double y;
			int pointNo = 0;
			while (cin >> x >> y)
			{
				pointNo++;
				if (x == 9999.9 && y == 9999.9) return 0;

				bool notContained = true;
				for (int i = 0; i < rects.size(); i++)
				{
					Rectangle r = rects[i];
					if (x > r.x1 && x < r.x2 && y < r.y1 && y > r.y2)
					{
						cout << "Point " << pointNo << " is contained in figure " << i+1 << endl;
						notContained = false;
					}
				}
				if (notContained)
					cout << "Point " << pointNo << " is not contained in any figure" << endl;
			}
		}
		cin.ignore(1000, '\n');
	}
	return 0;					
}