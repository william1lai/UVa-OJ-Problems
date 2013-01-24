#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
   string s;
   char c;

   while (getline(cin, s))
   {
      int words = 0;
      //check for letter
      for (int i = 0; i < s.length(); i++)
      {
         c = s[i];
         if (isalpha(c))
         {
            i++;
            c = s[i];
            while (isalpha(c))
            {
               i++;
               c = s[i];
            }
            words++;
         }
      }
      cout << words << endl;
   }
   return 0;         
}