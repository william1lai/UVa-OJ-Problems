#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
   int n;
   cin >> n;

   int f;
   int s;
   int a;
   int fr;

   int sum;

   for (int i = 0; i < n; i++)
   {
      sum = 0;
      cin >> f;
      for (int j = 0; j < f; j++)
      {
         cin >> s >> a >> fr;
         sum = sum + s*fr;
      }
      cout << sum << endl;
   }
   return 0;
}