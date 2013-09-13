#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int Z;
	int I;
	int M;
	int L;
	int caseno = 1;

	while (cin >> Z >> I >> M >> L)
	{
		if (Z == 0 && I == 0 && M == 0 && L == 0)
			return 0;

		bool already[10000];
		memset(already, false, 10000*sizeof(bool));
		Z = Z % M;
		I = I % M;

		int count = 0;
		int temp = L;

		temp = (Z*temp + I) % M;
		already[temp] = true;
		count++;
		while (temp != L)
		{
			temp = (Z*temp + I) % M;
			
			if (already[temp])
				break;

			already[temp] = true;
			count++;
		}

		cout << "Case " << caseno << ": " << count << endl;
		caseno++;
	}
	return 0;
}