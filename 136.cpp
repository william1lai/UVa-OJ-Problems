#include <cstdlib>
#include <iostream>

using namespace std;

bool checkNum(int n)
{
   if (n == 1)
   {
      return true;
   }
   else
   {
      if (n % 2 == 0)
      {
         return checkNum(n / 2);
      }
      else if (n % 3 == 0)
      {
         return checkNum(n / 3);
      }
      else if (n % 5 == 0)
      {
         return checkNum(n / 5);
      }
      else
      {
         return false;
      }
   }
}

int main()
{
   int count = 0;
   int num = 1;
   while (count != 1500)
   {
      if (checkNum(num))
      {
         count++;
      }
      num++;
   }
   cout << num << endl;
   return 0;
}