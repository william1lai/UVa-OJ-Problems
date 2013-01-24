#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
   int m;
   int n;
   while (cin >> m >> n)
   {
      cout << m << " " << n << " ";

      if (m > n)
      {
         int p = m;
         m = n;
         n = p;
      }
      
      int max = 0;

      for (int i = m; i <= n; i++)
      {
         int count = 1;
         int temp = i;
         while (temp != 1)
         {
            if (temp % 2 == 1)
            {
               temp = (temp * 3) + 1;
            }
            else 
            {
                temp = temp / 2;
            }
            count++;
         }

         if (count > max)
         {
            max = count;
         }
      }
      cout << max << endl;
   }

   return 0;
}

		