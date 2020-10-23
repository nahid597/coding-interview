#include<bits/stdc++.h>

using namespace std;

int main()
{

   int x = 6 , y = 3;

   for(int i = 0; i < y; i++)
   {
       if(x & (1 << i))
         cout << i << endl;
   }

    return 0;
}
