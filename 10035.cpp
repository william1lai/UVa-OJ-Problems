#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
   int a, b;
   cin >> a >> b;
   
   while ((a != 0) && (b != 0))
   {
      int total = 0;
      int carry = 0;
      int righta = a % 10;
      int rightb = b % 10;
      a = a / 10;
      b = b / 10;
      
      if (righta + rightb > 9)
      {
         carry = 1;
         total++;
      }
      
      while (a > 0 && b > 0)
      {
         righta = a % 10;
         rightb = b % 10;
         a = a / 10;
         b = b / 10;
         
         if (carry + righta + rightb > 9)
         {
            carry = 1;
            total++;
         }
         else
         {
            carry = 0;
         }
      }
      if (total == 0)
      {
         cout << "No carry operation." << endl;
      }
      else if (total > 1)
      {
         cout << total << " carry operations." << endl;
      }
      else
      {
         cout << "1 carry operation." << endl;
      }
      cin >> a >> b;
   }
   return 0;
}