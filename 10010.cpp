#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;
	cin.ignore(1000, '\n');

	bool first = true;
	
	for (int i = 0; i < ncases; i++)
	{		
		char temp;
		if (cin.get(temp))
		{
			if (temp == '\n' && !first)
				cout << endl;
			else
				cin.putback(temp);
		}
		first = false;

		int rows;
		int cols;
		cin >> rows >> cols;
		cin.ignore(1000, '\n');

		char** grid = new char*[rows];
		for (int j = 0; j < rows; j++)
		{
			grid[j] = new char[cols];
			for (int k = 0; k < cols; k++)
			{
				char c;
				cin.get(c);
				c = tolower(c);
				grid[j][k] = c;
			}
			cin.ignore(1000, '\n');
		}

		int queries;
		cin >> queries;
		cin.ignore(1000, '\n');

		for (int j = 0; j < queries; j++)
		{
			string name;
			getline(cin, name);

			for (int pikachu = 0; pikachu < name.length(); pikachu++)
			{
				if (name[pikachu] == ' ')
				{
					name = name.substr(0, pikachu);
					break;
				}
			}

			for (int z = 0; z < name.length(); z++)
				name[z] = tolower(name[z]);

			bool found = false;
			int fr = -1;
			int fc = -1;
			for (int r = 0; r < rows; r++)
			{
				for (int c = 0; c < cols; c++)
				{
					if (grid[r][c] == name[0])
					{
						//check left & right
						if (c + 1 >= name.length())
						{
							int index = 1;
							for (int cc = c - 1; cc > c - (int)name.length(); cc--)
							{
								if (grid[r][cc] == name[index])
									index++;
								else
									break;
							}
							if (index == name.length()) //found
							{
								fr = r;
								fc = c;
								found = true;
								break;
							}
						}
						if (cols - c >= name.length())
						{
							int index = 1;
							for (int cc = c + 1; cc < c + name.length(); cc++)
							{
								if (grid[r][cc] == name[index])
									index++;
								else
									break;
							}
							if (index == name.length()) //found
							{
								fr = r;
								fc = c;
								found = true;
								break;
							}
						}

						//check up and down
						if (r + 1 >= name.length())
						{
							int index = 1;
							for (int rr = r - 1; rr > r - (int)name.length(); rr--)
							{
								if (grid[rr][c] == name[index])
									index++;
								else
									break;
							}
							if (index == name.length()) //found
							{
								fr = r;
								fc = c;
								found = true;
								break;
							}
						}
						if (rows - r >= name.length())
						{
							int index = 1;
							for (int rr = r + 1; rr < r + name.length(); rr++)
							{
								if (grid[rr][c] == name[index])
									index++;
								else
									break;
							}
							if (index == name.length()) //found
							{
								fr = r;
								fc = c;
								found = true;
								break;
							}
						}

						//check diags
						if (c + 1 >= name.length() && r + 1 >= name.length())
						{
							int index = 1;
							for (int cc = c - 1, rr = r - 1; cc > c - (int)name.length() && rr > r - (int)name.length(); cc--, rr--)
							{
								if (grid[rr][cc] == name[index])
									index++;
								else
									break;
							}
							if (index == name.length()) //found
							{
								fr = r;
								fc = c;
								found = true;
								break;
							}
						}
						if (cols - c >= name.length() && rows - r >= name.length())
						{
							int index = 1;
							for (int cc = c + 1, rr = r + 1; cc < c + name.length() && rr < r + name.length(); cc++, rr++)
							{
								if (grid[rr][cc] == name[index])
									index++;
								else
									break;
							}
							if (index == name.length()) //found
							{
								fr = r;
								fc = c;
								found = true;
								break;
							}
						}
						if (c + 1 >= name.length() && rows - r >= (int)name.length())
						{
							int index = 1;
							for (int cc = c - 1, rr = r + 1; cc > c - (int)name.length() && rr < r + (int)name.length(); cc--, rr++)
							{
								if (grid[rr][cc] == name[index])
									index++;
								else
									break;
							}
							if (index == name.length()) //found
							{
								fr = r;
								fc = c;
								found = true;
								break;
							}
						}
						if (cols - c >= (int)name.length() && r + 1 >= name.length())
						{
							int index = 1;
							for (int cc = c + 1, rr = r - 1; cc < c + name.length() && rr > r - (int)name.length(); cc++, rr--)
							{
								if (grid[rr][cc] == name[index])
									index++;
								else
									break;
							}
							if (index == name.length()) //found
							{
								fr = r;
								fc = c;
								found = true;
								break;
							}
						}				
					}

					if (found)
						break;
				}

				if (found)
					break;
			}

			if (fr >= 0 && fc >= 0)
				cout << fr + 1 << " " << fc + 1 << endl;
		}
	}
	return 0;
}