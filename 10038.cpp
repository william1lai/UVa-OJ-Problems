#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
   int n;
   bool* bptr;
   while (cin >> n)
   {
      bptr = new bool[n];
      int temp1, temp2;
      cin >> temp1;
      for (int i = 1; i < n; i++)
      { 
        cin >> temp2;
        int diff = abs(temp2 - temp1);
        if (diff > 0 && diff < n)
        {
           bptr[diff] = true;
        }
        temp1 = temp2;
      }
       
      bool j = false;
      for (int i = 1; i < n; i++)
      {
         if (bptr[i] == false)
         {
            cout << "Not jolly" << endl;
            j = true;
            break;
         }
      }
      if (j != true)
      {
         cout << "Jolly" << endl;
      }
   }
   return 0;
}