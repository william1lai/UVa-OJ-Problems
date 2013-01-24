#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
   long long b1, g1, c1;
   long long b2, g2, c2;
   long long b3, g3, c3;

   string encoding;
   long long min = -1;

   while (cin >> b1 >> g1 >> c1
              >> b2 >> g2 >> c2
              >> b3 >> g3 >> c3)
   {
      min = b2 + b3 + c1 + c3 + g1 + g2; //bcg
      encoding = "BCG";

      long long temp = b2 + b3 + g1 + g3 + c1 + c2; //bgc
      if (temp < min)
      {
         min = temp;
         encoding = "BGC";
      }
      
      temp = c2 + c3 + b1 + b3 + g1 + g2; //cbg
      if (temp < min)
      {
         min = temp;
         encoding = "CBG";
      }
      
      temp = c2 + c3 + g1 + g3 + b1 + b2; //cgb
      if (temp < min)
      {
         min = temp;
         encoding = "CGB";
      }

      temp = g2 + g3 + c1 + c2 + b1 + b3; //gbc
      if (temp < min)
      {
         min = temp;
         encoding = "GBC";
      }

      temp = g2 + g3 + c1 + c3 + b1 + b2; //gcb
      if (temp < min)
      {
         min = temp;
         encoding = "GCB";
      }
      
      cout << encoding << " " << min << endl;
   }
   return 0;
}