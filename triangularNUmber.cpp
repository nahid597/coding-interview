#include<bits/stdc++.h>

using namespace std;


int main()
{

   int x[10000] = {0};

   for(int i = 1; i <= 10000; i++)
   {
      x[i] = x[i-1] + i;
      //cout << x[i] << endl;
   }

   //cout << x[0] << endl;

    int t, n;

    cin >> t;

    int flag = 0;

    while(t--)
    {
       cin >> n;
       flag = 0;

       for(int i = 1; i <= 10000; i++)
       {
          if(n == x[i])
          {
             flag = 1;
             break;
          }
       }

       cout << flag << endl;


    }




    return 0;
}
