#include <cstdlib>
#include <iostream>

using namespace std;

long long revAdd(long long n)
{
   long long nn = n;
   long long temp = 0;
   while (n > 0)
   {
      temp = (temp * 10) + (n % 10);
      n = n / 10;
   }
   return (temp + nn);
}

bool checkPal(long long n)
{
   long long nn = n;
   long long temp = 0;
   while (n > 0)
   {
      temp = (temp * 10) + (n % 10);
      n = n / 10;
   }
   return (temp == nn);
}

int main()
{
   int cases;
   cin >> cases;
   long long n;

   for (int i = 0; i < cases; i++)
   {
      int count = 0;
      cin >> n;
      while (!checkPal(n))
      {
         n = revAdd(n);
         count++;
      }
      cout << count << " " << n << endl;
   }
   return 0;
}