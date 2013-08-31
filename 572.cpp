#include <iostream>
#include <queue>

using namespace std;

struct Point
{
	int x;
	int y;
};

int main()
{
	int r;
	int c;
	cin >> r >> c;
	while (r != 0 && c != 0)
	{
		int count = 0;
		Point first;
		first.x = -1; first.y = -1;
		bool** oil = new bool*[r];
		for (int i = 0; i < r; i++)
		{
			oil[i] = new bool[c];
			for (int j = 0; j < c; j++)
			{
				char c;
				cin >> c;
				if (c == '@')
				{
					oil[i][j] = true;
					if (first.x < 0 && first.y < 0)
					{
						first.x = j; first.y = i;
					}
				}
				else oil[i][j] = false;
			}
		}

		queue<Point> q;
		if (first.x >= 0 && first.y >= 0)
			q.push(first);
		bool done = false;

		if (q.empty())
		{
			cout << 0 << endl;
			cin >> r >> c;
			continue;
		}

		while(!done)
		{
			while (!q.empty())
			{
				Point next = q.front();
				q.pop();
				oil[next.y][next.x] = false;
				if (next.y > 0)
				{
					if (oil[next.y - 1][next.x])
					{
						Point temp;
						temp.y = next.y-1; temp.x = next.x;	
						q.push(temp);
					}
					if (next.x > 0 && oil[next.y-1][next.x-1])
					{
						Point temp;
						temp.y = next.y-1; temp.x = next.x-1;
						q.push(temp);	
					}
					if (next.x < c-1 && oil[next.y-1][next.x+1])
					{
						Point temp;
						temp.y = next.y-1; temp.x = next.x+1;
						q.push(temp);
					}
				}
				if (next.y < r-1)
				{
					if (oil[next.y+1][next.x])
					{
						Point temp;
						temp.y = next.y+1; temp.x = next.x;
						q.push(temp);
					}
					if (next.x > 0 && oil[next.y+1][next.x-1])
					{
						Point temp;
						temp.y = next.y+1; temp.x = next.x-1;
						q.push(temp);	
					}
					if (next.x < c-1 && oil[next.y+1][next.x+1])
					{
						Point temp;
						temp.y = next.y+1; temp.x = next.x+1;
						q.push(temp);
					}
				}
				if (next.x > 0 && oil[next.y][next.x-1])
				{
					Point temp;
					temp.y = next.y; temp.x = next.x-1;
					q.push(temp);
				}
				if (next.x < c-1 && oil[next.y][next.x+1])
				{
					Point temp;
					temp.y = next.y; temp.x = next.x+1;
					q.push(temp);
				}
			}

			count++;
			done = true;
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					if (oil[i][j])
					{
						Point temp;
						temp.y = i; temp.x = j;
						q.push(temp);
						done = false;
						break;
					}
				}
				if (!done)
					break;
			}
		}			

		cout << count << endl;
		cin >> r >> c;
	}
	return 0;
}