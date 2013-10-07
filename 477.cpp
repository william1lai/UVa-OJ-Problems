#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rectangle
{
	double x1;
	double y1;
	double x2;
	double y2;
	int id;
};

struct Circle
{
	double x;
	double y;
	double r;
	int id;
};

bool inRect(double x, double y, Rectangle r)
{
	return ((x > r.x1 && x < r.x2) && (y < r.y1 && y > r.y2));
}

bool inCircle(double x, double y, Circle c)
{
	double distsq = (x - c.x)*(x - c.x) + (y - c.y)*(y-c.y);
	return (c.r*c.r > distsq);
}

int main()
{
	vector<Rectangle> rects;
	vector<Circle> circs;

	char type;
	int id = 1;
	while (cin.get(type))
	{
		if (type == '*')
			break;

		if (type == 'r')
		{
			Rectangle r;
			cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
			r.id = id;
			id++;
			rects.push_back(r);
		}
		else
		{
			Circle c;
			cin >> c.x >> c.y >> c.r;
			c.id = id;
			id++;
			circs.push_back(c);
		}
		cin.ignore(1000, '\n');
	}

	double x;
	double y;
	int pointno = 1;
	while (cin >> x >> y)
	{
		if (x == 9999.9 && y == 9999.9)
			return 0;

		vector<int> contained;
		for (int i = 0; i < rects.size(); i++)
		{
			if (inRect(x, y, rects[i]))
				contained.push_back(rects[i].id);
		}
		for (int i = 0; i < circs.size(); i++)
		{
			if (inCircle(x, y, circs[i]))
				contained.push_back(circs[i].id);
		}

		sort(contained.begin(), contained.end());

		if (contained.size() == 0)
		{
			cout << "Point " << pointno << " is not contained in any figure" << endl;
		}
		else
		{
			for (int i = 0; i < contained.size(); i++)
			{
				cout << "Point " << pointno << " is contained in figure " << contained[i] << endl;
			}		
		}

		pointno++;
	}
	return 0;
}