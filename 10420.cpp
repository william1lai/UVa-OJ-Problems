#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct CountryNames
{
	string country;
	set<string> names;
};

bool isLessThan(CountryNames first, CountryNames second)
{
	return first.country < second.country;
}

int main()
{
	set<CountryNames, bool(*)(CountryNames, CountryNames)> my_set(isLessThan);

	int nlines;
	cin >> nlines;
	cin.ignore(1000, '\n');
	for (int i = 0; i < nlines; i++)
	{
		string line;
		getline(cin, line);
		istringstream iss(line);

		string countryInput;
		iss >> countryInput;
		bool existsAlready = false;
		set<CountryNames, bool(*)(CountryNames, CountryNames)>::iterator it;
		for (it = my_set.begin(); it != my_set.end(); it++)
		{
			if ((*it).country == countryInput)
			{
				existsAlready = true;
				break;
			}
		}

		string nameInput;
		getline(iss, nameInput);
		if (!existsAlready)
		{
			CountryNames cn;
			cn.country = countryInput;

			cn.names.insert(nameInput);

			my_set.insert(cn);
		}
		else
		{
			CountryNames cn = (*it);
			cn.names.insert(nameInput);

			my_set.erase(it);
			my_set.insert(cn);
		}
	}

	for (set<CountryNames, bool(*)(CountryNames, CountryNames)>::iterator it2 = my_set.begin(); it2 != my_set.end(); it2++)
	{
		cout << (*it2).country << " " << (*it2).names.size() << endl;
	}

	return 0;
}