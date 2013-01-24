#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main()
{
   char c;
   bool hasFront = false;

   while (cin.get(c))
   {
      if (c != '\"')
      { 
         cout << c;
      }
      else
      {
         if (!hasFront)
         {
            cout << "``";
         }
         else
         {
            cout << "''";
         }
         hasFront = !hasFront;
      }
   }
   return 0;
}