#include <iostream>
#include <cmath>
#include <cfloat>
#include <vector>
#include "stdio.h"

using namespace std;

struct Point
{
	double x;
	double y;
};

double distances(Point p1, Point p2) //if you name this "distance", it conflicts with cmath's std::distance function
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int main()
{
	int ncases;
	cin >> ncases;

	for (int cs = 0; cs < ncases; cs++)
	{
		if (cs != 0)
			printf("\n");

		int npts;
		cin >> npts;

		vector<Point> m_pts;
		double** dist = new double*[npts];
		bool* connected = new bool[npts];
		for (int i = 0; i < npts; i++)
		{
			connected[i] = false;
			dist[i] = new double[npts];
		}

		for (int i = 0; i < npts; i++)
		{
			double x;
			double y;
			cin >> x >> y;
			Point temp;
			temp.x = x;
			temp.y = y;
			m_pts.push_back(temp);
		}

		for (int i = 0; i < npts; i++)
		{
			for (int j = i; j < npts; j++)
			{
				double pikachu = distances(m_pts[i], m_pts[j]);
				dist[i][j] = pikachu;
				dist[j][i] = pikachu;
			}
		}
		
		double sum = 0.0;
		int edgeCount = 0;
		connected[0] = true;
		while (edgeCount != npts - 1)
		{
			double min = DBL_MAX;
			int m1;
			int m2;
			for (int i = 0; i < npts; i++)
			for (int j = 0; j < npts; j++)
			{
				if (dist[i][j] < min)
				{
					if (connected[i] && !connected[j])
					{
						min = dist[i][j];
						m1 = i;
						m2 = j;
					}
				}
			}

			sum = sum + dist[m1][m2];
			connected[m2] = true;
			edgeCount++;
		}

		printf("%.2f\n", sum);
	}
	return 0;
}